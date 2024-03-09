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
	for (size_t i = 0; i < x_size; i++)
	{
		generated_tileset[i] = new Tile * [y_size];
		for (size_t j = 0; j < y_size; j++)
		{
			generated_tileset[i][j] = NULL;
		}
	}

	/* DEBUG Populate the tile array */

	for (size_t i = 0; i < x_size; i++)
	{
		for (size_t j = 0; j < y_size; j++)
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
	for (size_t i = 0; i < x_size; i++)
	{
		generated_tileset[i] = new Tile * [y_size];
		for (size_t j = 0; j < y_size; j++)
		{
			generated_tileset[i][j] = new Tile();
		}
	}
	return generated_tileset;
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

	for (size_t i = 0; i < world_cfg_ptr->grid_x_size; i++)
	{
		for (size_t j = 0; j < world_cfg_ptr->grid_y_size; j++)
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

	struct TectonicPlateCount main_tectonic_plates_count = GetPlanetTectonicPlatesCount(world_cfg_ptr->planet_type);

	/*
		1) Generate the tectonic plates.
			*need to design best way to create plates
		2)Populate plates with basic tiles
		3)Assign tectonic movments
		4)Assign Tile heights based on movments of plates
	 */
	return NULL;
}