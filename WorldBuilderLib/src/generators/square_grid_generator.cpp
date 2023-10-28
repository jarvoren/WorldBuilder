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

Tile*** SquareGridGenerator::GenerateBasicTileset()
{

	//NOTE TO SELF
	//GENERATOR MUST BE AWARE OF THE SCALE IT OPERATES IN - plates will work only if we know how far away from the plate
	//boundary the creation events take precedence. So first step is to calculate the size of the tile in relation to planet size.

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