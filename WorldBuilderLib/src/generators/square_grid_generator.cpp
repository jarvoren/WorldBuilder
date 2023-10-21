#include <generators/square_grid_generator.h>

Tile*** GenerateTileset(uint32_t x_size, uint32_t y_size)
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
