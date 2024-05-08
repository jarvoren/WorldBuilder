#include <generators/square_grid_generator.h>

SquareGridGenerator::SquareGridGenerator(WorldConfig* cfg)
{
	world_cfg_ptr = cfg;
}

Tile*** SquareGridGenerator::GenerateTestTileset(uint32_t x_size, uint32_t y_size)
{
	int se = 8000;
	/* Allocate the arrays for the tileset */
	Tile*** generated_tileset = new Tile * *[x_size];
	for (int i = 0; i < x_size; i++)
	{
		generated_tileset[i] = new Tile * [y_size];
		for (int j = 0; j < y_size; j++)
		{
			generated_tileset[i][j] = NULL;
		}
	}

	/* DEBUG Populate the tile array */

	for (int i = 0; i < x_size; i++)
	{
		for (int j = 0; j < y_size; j++)
		{
			generated_tileset[i][j] = NULL;
			generated_tileset[i][j] = new Tile(i, j, se++, generated_tileset, 60, 60);
		}
	}

	return generated_tileset;
}

/* Generate clear tileset */
Tile*** SquareGridGenerator::GenerateBasicTileset(uint32_t x_size, uint32_t y_size)
{
	Tile*** generated_tileset = new Tile * *[x_size];
	for (int i = 0; i < x_size; i++)
	{
		generated_tileset[i] = new Tile * [y_size];
		for (int j = 0; j < y_size; j++)
		{
			generated_tileset[i][j] = new Tile();
			generated_tileset[i][j]->coordinates.pos_x = i;
			generated_tileset[i][j]->coordinates.pos_y = j;
		}
	}
	return generated_tileset;
}

std::vector<TectonicPlate*> SquareGridGenerator::GetTectonicPlates()
{
	return created_plates;
}

/* Generate tileset of c-squares.
 * C-square individual "square" is in fact a trapeze in real messurments
 * square is for the presentation side.
 */
Tile*** SquareGridGenerator::GeneratePlanetsTileset()
{
	Tile*** tileset = GenerateBasicTileset(world_cfg_ptr->grid_x_size, world_cfg_ptr->grid_y_size);

	int top_equator_id = world_cfg_ptr->grid_y_size / 2;
	int equator_border_size = world_cfg_ptr->tile_size;

	int world_circumference = GetPlanetRadius(world_cfg_ptr->planet_type) * M_PI * 2;
	/* strangly named variable which is actualy pole to pole length
	 * so half of circumference (we are not doing elipsoid)
	 * used by the c-squares
	 */
	int world_height = world_circumference / 2;
	int universal_border_size = world_height / world_cfg_ptr->grid_y_size;

	for (int i = 0; i < world_cfg_ptr->grid_x_size; i++)
	{
		for (int j = 0; j < world_cfg_ptr->grid_y_size; j++)
		{

			/* y border size is always the tile size and not affected by c-squares */
			tileset[i][j]->y_border_size = universal_border_size;

			if (j < top_equator_id)
			{
				tileset[i][j]->x_top_border_size = j / top_equator_id * universal_border_size;
				tileset[i][j]->x_bottom_border_size = j + 1 / top_equator_id * universal_border_size;
			}
			else
			{
				int dividend = world_cfg_ptr->grid_y_size - j - 1;
				tileset[i][j]->x_bottom_border_size = dividend / top_equator_id * universal_border_size;
				tileset[i][j]->x_top_border_size = dividend + 1 / top_equator_id * universal_border_size;
			}
		}
	}

	PopulateGridWithTectonicStartPoints();

	ExpandPlatePoints();
	/*
		1) Generate the tectonic plates.
			*need to design best way to create plates
		2)Populate plates with basic tiles
		3)Assign tectonic movments
		4)Assign Tile heights based on movments of plates
	 */
	return NULL;
}

void SquareGridGenerator::GenerateAndSaveNewTectonicPlates(std::vector<Point> saved_points, bool is_major)
{
	for (int i = 0; i < saved_points.size(); i++)
	{
		TectonicPlate* new_plate = new TectonicPlate();
		new_plate->is_major = is_major;
		/* In the event of plate already being asigned to this tile (only when minor overwrites major)
		 * we take tile to the right if possible if not we assign plate to left one
		 */
		if(generator_tileset[saved_points[i].pos_x][saved_points[i].pos_y]->plate)
			if (world_cfg_ptr->grid_x_size = saved_points[i].pos_x)
				generator_tileset[saved_points[i].pos_x-1][saved_points[i].pos_y]->plate = new_plate;
			else
				generator_tileset[saved_points[i].pos_x + 1][saved_points[i].pos_y]->plate = new_plate;
		else
			generator_tileset[saved_points[i].pos_x][saved_points[i].pos_y]->plate = new_plate;
		created_plates.push_back(new_plate);
	}
}

void SquareGridGenerator::PopulateGridWithTectonicStartPoints()
{
	TectonicPlateCount plate_counts = GetPlanetTectonicPlatesCount(world_cfg_ptr->planet_type);
	
	/* This is implementation of moddified Poisson Disk distribution */
	/* Calculate maximum radius for major and minor plates */
	int max_radius_major = (world_cfg_ptr->grid_x_size + world_cfg_ptr->grid_y_size) / plate_counts.major_plates_count;
	int max_radius_minor = (world_cfg_ptr->grid_x_size + world_cfg_ptr->grid_y_size) / plate_counts.minor_plates_count;
	int min_radius_major = (world_cfg_ptr->grid_x_size + world_cfg_ptr->grid_y_size) / plate_counts.major_plates_count / RADIUS_DIVIDER;
	int min_radius_minor = (world_cfg_ptr->grid_x_size + world_cfg_ptr->grid_y_size) / plate_counts.minor_plates_count / RADIUS_DIVIDER;

	/* Get major plates starting points */
	std::vector<Point> saved_points = GetPlateCoordinates(plate_counts.major_plates_count, max_radius_major, min_radius_major);

	/* Save the coordinates and create the major plate objects assigned to a starting point */
	GenerateAndSaveNewTectonicPlates(saved_points, true);

	/* Do the same for minor plates */
	saved_points = GetPlateCoordinates(plate_counts.minor_plates_count, max_radius_minor, min_radius_minor);

	GenerateAndSaveNewTectonicPlates(saved_points, false);

	//NEXT SETUP SOME KIND OF PRINTING OF THE WORLD SOLUTION
	//REFACTOR TO HAVE TILESET AS A PART OF GENERATOR AND RETURN IN THE END ?
}

std::vector<Point> SquareGridGenerator::GetPlateCoordinates(int plate_count, int max_radius, int min_radius)
{
	std::vector<Point> saved_points;
	for (int i = 0; i < plate_count; i++)
	{
		for (int i = 0; i < world_cfg_ptr->generator_config.poisson_retry_count; i++)
		{
			Point temp_point = {};
			if (saved_points.empty())
			{
				Point temp_point = GetPoissonPointPositiveOnly({ 0,0 }, max_radius, min_radius);
			}
			else
			{
				Point temp_point = GetPoissonPointPositiveOnly(saved_points.back(),
					max_radius, min_radius);
			}
			if (ValidatePoint(&saved_points, temp_point, world_cfg_ptr->grid_x_size,
				world_cfg_ptr->grid_y_size, min_radius))
			{
				saved_points.push_back(temp_point);
			}
		}
	}
	return saved_points;
}

void SquareGridGenerator::ExpandPlatePoints()
{

}
