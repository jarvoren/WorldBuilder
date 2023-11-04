#include <generators/square_grid_generator.h>

SquareGridGenerator::SquareGridGenerator(WorldConfig* cfg)
{
	world_cfg_ptr = cfg;
}

Tile*** SquareGridGenerator::GenerateTestTileset(uint32_t x_size, uint32_t y_size)
{
	int se = 8000;
	/* Allocate the arrays for the tileset */
	Tile*** generated_tileset = new Tile**[x_size];
	for (size_t i = 0; i < x_size; i++)
	{
		generated_tileset[i] = new Tile*[y_size];
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
			generated_tileset[i][j] = new Tile(i, j, se++, generated_tileset, 60,60);
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
	//NOTE TO SELF
	//GENERATOR MUST BE AWARE OF THE SCALE IT OPERATES IN - plates will work only if we know how far away from the plate
	//boundary the creation events take precedence. So first step is to calculate the size of the tile in relation to planet size.
	//also the fact that c-square representation changes tile size depending 

	
	//############################################################
	//HIGHEST in y axis SQUARE x size SHOULD BE the y border size divided by count of squares in the x grid!!!!!!!!!
	//############################################################
	int top_equator_id = world_cfg_ptr->grid_y_size / 2;
	int equator_border_size = world_cfg_ptr->tile_size;

	/* Bottom border of tile nearest to any pole */
	double polemost_tile_bottom_border = equator_border_size / world_cfg_ptr->grid_x_size;

	int planet_radius = GetPlanetRadius(world_cfg_ptr->planet_type);

	for (size_t i = 0; i < world_cfg_ptr->grid_x_size; i++)
	{
		for (size_t j = 0; j < world_cfg_ptr->grid_y_size; j++)
		{
			//BEFORE RETHINK THE TILE COUNT IN Y AND X DIRECTIONS MAYBE THIS SHOULD BE ALWAYS x count = y count 

			// CHECK WHICH WAY WE GO TO OR FROM THE EQUATOR
			// FIND THE RATIO FOR THE TOP OR BOTTOM BORDER
			// ASIGN THE BORDER SIZE ACORDING TO THE RATIO
			/* y border size is always the tile size and not affected by c-squares */
			tileset[i][j]->x_border_size = equator_border_size
		}
	}
	//NOTE TO SELF
	// does bigger planet mean bigger plates? Is size of plate relative that is main question. Probably with no answer since we know not
	// of other planets with similar tectonics
	 /*
		1) Generate the tectonic plates.
			*need to design best way to create plates
		2)Populate plates with basic tiles
		3)Assign tectonic movments
		4)Assign Tile heights based on movments of plates
	 */
	return NULL;
}