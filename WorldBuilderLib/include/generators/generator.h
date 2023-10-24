#ifndef H_GRID_GENERATOR_H
#define H_GRID_GENERATOR_H

#include <grid_elements/tile.h>

struct GeneratorConfig
{

};

class Generator
{
public:
	virtual Tile*** GenerateBasicTileset(GeneratorConfig cfg) = 0;
};

#endif // H_SQUARE_GRID_GENERATOR_H