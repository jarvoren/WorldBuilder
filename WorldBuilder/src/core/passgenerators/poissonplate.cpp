#include "passgenerators/poissonplate.h"
#include <string>

ErrorCode PoissonPlate::CreateTectonicPlate(PointInfo point, std::vector<Tile> &tileset,
											PlateType type)
{
	ErrorCode ec = ErrorCode::Succes;

	std::shared_ptr<TectonicPlateInformation> plate = std::make_shared<TectonicPlateInformation>();

	plate->origin_x = point.x;
	plate->origin_y = point.y;

	// can add density configuration for type or by planet type etc;
	plate->density =
		static_cast<PlateDensity>(RandomInt(1, static_cast<int>(PlateDensity::Last) - 1));

	plate->plate_direction.dx = RandomInt(-1, 1);
	plate->plate_direction.dy = RandomInt(-1, 1);

	plate->type = type;

	generated_plates.push_back(std::move(plate));

	log_error_code(ec);
	return ec;
}

uint64_t PoissonPlate::CalculateDistance(uint8_t plate_count)
{
	return std::sqrt((size_x * size_y) /
					 (plate_count * tectonics_config.poisson_algorithm_distance_multiplier));
}

ErrorCode PoissonPlate::Configure(ConfigData &configuration)
{
	this->size_x = configuration.size_x;
	this->size_y = configuration.size_y;

	tectonics_config = configuration.plateData;

	// Use errorcode for advanced configuration mismatch - futureproofing
	return ErrorCode::Succes;
}

ErrorCode PoissonPlate::Populate(std::vector<Tile> &tileset, PlateType type)
{
	ErrorCode ec = ErrorCode::Succes;
	uint64_t distance = 0;

	switch (type)
	{
	case PlateType::Major:
		if (tectonics_config.minDistanceOverrideMajor != 0)
			distance = tectonics_config.minDistanceOverrideMajor;
		else
			distance = CalculateDistance(tectonics_config.major_plate_count);
		break;
	case PlateType::Minor:
		if (tectonics_config.minDistanceOverrideMinor != 0)
			distance = tectonics_config.minDistanceOverrideMinor;
		else
			// distance = (size_x + size_y) / 2 / (tectonics_config.minor_plate_count + 2);
			distance = CalculateDistance(tectonics_config.minor_plate_count);
		break;
	}

	std::vector<PointInfo> generatedPoints =
		GeneratePoisson(distance, tectonics_config.poisson_algorithm_retries);

	for (int i = 0; i < generatedPoints.size(); i++)
	{
		ec = CreateTectonicPlate(generatedPoints[i], tileset, type);
	}

	for (auto plate : generated_plates)
	{
		if (plate->type == type)
		{
			log_info("Calculation of plate: " +
					 std::to_string(plate->origin_x * size_x + plate->origin_y));
			auto &tile = tileset[plate->origin_x * size_x + plate->origin_y];
			// If we already have a plate there we need to place a plate
			if (tile.tectonic_info != nullptr)
			{
				if (plate->origin_x < size_x - 2)
					plate->origin_x++;
				else
					plate->origin_x--;

				tile = tileset[plate->origin_x * size_x + plate->origin_y];
			}
			tile.tectonic_info = plate;
		}
	}

	return ec;
}

ErrorCode PoissonPlate::RunPass(std::vector<Tile> &tileset)
{
	ErrorCode ec = ErrorCode::Succes;

	ec = Populate(tileset, PlateType::Minor);
	ec = Populate(tileset, PlateType::Major);

	return ec;
}

std::vector<PointInfo> PoissonPlate::GeneratePoisson(uint64_t distance, int k = 30)
{
	/*
	  Birdson Algorithm
	  Create a cell representation of tileset and try to populate it;

	   Math:cellSize = r / sqrt(2).
	   We use long double to keep precision for large uint64 ranges.
	  */
	long double cellSize = (long double)distance / 1.4142135623730950488L;

	uint64_t cols = (uint64_t)std::ceil((long double)size_x / cellSize);
	uint64_t rows = (uint64_t)std::ceil((long double)size_y / cellSize);

	// 1D Grid for O(1) spatial lookups. Initialized to 0xFFFFFFFFFFFFFFFF (max uint64)
	// representing an empty cell, since 0 is a valid point index.
	const uint64_t EMPTY = 0xFFFFFFFFFFFFFFFF;
	std::vector<uint64_t> grid(cols * rows, EMPTY);

	std::vector<PointInfo> points;
	std::vector<uint64_t> active;

	// 1. Seed: Place first point
	PointInfo p0(RandomUint64(0, size_x - 1), RandomUint64(0, size_y - 1));
	points.push_back(p0);
	active.push_back(0);
	grid[(uint64_t)(p0.x / cellSize) + (uint64_t)(p0.y / cellSize) * cols] = 0;

	while (!active.empty())
	{
		// Pick a random index from the active list
		int listIdx = rand() % active.size();
		PointInfo parent = points[active[listIdx]];
		bool found = false;

		for (int i = 0; i < k; ++i)
		{
			// Generate candidate in hollow ring [r, 2r]
			// We scale the RNG to simulate floating point angles/distances
			long double angle = (RandomUint64(0, 628318) / 100000.0L);
			long double dist = (RandomUint64(distance * 1000, 2 * distance * 1000) / 1000.0L);

			uint64_t candX = (uint64_t)(parent.x + dist * std::cos(angle));
			uint64_t candY = (uint64_t)(parent.y + dist * std::sin(angle));
			PointInfo cand = {candX, candY};

			// Bounds check
			if (cand.x < size_x && cand.y < size_y)
			{
				uint64_t c = (uint64_t)(cand.x / cellSize);
				uint64_t f = (uint64_t)(cand.y / cellSize);
				bool ok = true;

				// Check 5x5 neighbors in the grid
				uint64_t minX = (c > 2) ? c - 2 : 0;
				uint64_t maxX = std::min(cols - 1, c + 2);
				uint64_t minY = (f > 2) ? f - 2 : 0;
				uint64_t maxY = std::min(rows - 1, f + 2);

				for (uint64_t y = minY; y <= maxY && ok; ++y)
				{
					for (uint64_t x = minX; x <= maxX; ++x)
					{
						uint64_t gIdx = grid[x + y * cols];
						if (gIdx != EMPTY)
						{
							// Using __int128 or careful subtraction to avoid overflow on large
							// uint64
							long double dx = (long double)cand.x - (long double)points[gIdx].x;
							long double dy = (long double)cand.y - (long double)points[gIdx].y;
							if (dx * dx + dy * dy < (long double)distance * distance)
							{
								ok = false;
								break;
							}
						}
					}
				}

				if (ok)
				{
					uint64_t newIdx = points.size();
					grid[c + f * cols] = newIdx;
					active.push_back(newIdx);
					points.push_back(cand);
					found = true;
					break;
				}
			}
		}

		if (!found)
		{
			active.erase(active.begin() + listIdx);
		}
	}
	return points;
}
