#ifndef PASSION_PLATE_H
#define PASSION_PLATE_H

#include "descriptors/config.h"
#include "descriptors/enums.h"
#include "descriptors/plate.h"
#include "descriptors/point.h"
#include "passobject.h"
#include "utilities/error_utilities.h"
#include "utilities/rng.h"
#include <cmath>
#include <cstdint>
#include <descriptors/tile.h>
#include <vector>

class PoissonPlate : public PassObject
{

	PlateTectonicsData tectonics_config;

	uint32_t size_x;
	uint32_t size_y;

	std::vector<std::shared_ptr<TectonicPlateInformation>> generated_plates;

	ErrorCode Configure(ConfigData &configuration) override;
	ErrorCode RunPass(std::vector<Tile> &tileset) override;
	ErrorCode Populate(std::vector<Tile> &tileset, PlateType type);
	uint64_t CalculateDistance(uint8_t plate_count);
	ErrorCode CreateTectonicPlate(PointInfo pointm, std::vector<Tile> &tileset, PlateType type);
	std::vector<PointInfo> GeneratePoisson(uint64_t distance, int k);
};

#endif // PASSION_PLATE_H
