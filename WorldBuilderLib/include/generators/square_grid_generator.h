#ifndef H_SQUARE_GRID_GENERATOR_H
#define H_SQUARE_GRID_GENERATOR_H

/* This should use the concept of c-squares to represent the globe or standard squares
 * if the globe variable is off.
 */

#include <grid_elements/tile.h>
#include <generators/generator.h>

class SquareGridGenerator : public Generator
{
public:
	Tile*** GenerateTestTileset(uint32_t x_size, uint32_t y_size);
	Tile*** GenerateBasicTileset(uint32_t x_size, uint32_t y_size);
};



#endif // H_SQUARE_GRID_GENERATOR_H