#ifndef H_GRID_GENERATOR_H
#define H_GRID_GENERATOR_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <grid_elements/tile.h>
#include <configs/configs_agregator.h>

class Generator
{
public:
	virtual Tile*** GeneratePlanetsTileset() = 0;
	virtual Tile*** GenerateTestTileset(uint32_t x_size, uint32_t y_size) = 0;
	WorldConfig* world_cfg_ptr;
};

#endif // H_GRID_GENERATOR_H