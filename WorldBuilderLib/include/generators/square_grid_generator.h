#ifndef H_SQUARE_GRID_GENERATOR_H
#define H_SQUARE_GRID_GENERATOR_H

/* This should use the concept of c-squares to represent the globe or standard squares
 * if the globe variable is off.
 */

#include <generators/generator.h>
#include <generators/planetary/sizes_generator.h>

class SquareGridGenerator : public Generator
{
public:
	SquareGridGenerator(WorldConfig* cfg);
	Tile*** GeneratePlanetsTileset() override;
	Tile*** GenerateTestTileset(uint32_t x_size, uint32_t y_size) override;
	Tile*** GenerateBasicTileset(uint32_t x_size, uint32_t y_size);
private:
	void PopulateGridWithTectonicStartPoints(Tile*** tileset, 
			struct TectonicPlateCount plate_counts);
	void ExpandPlatePoints(Tile*** tileset);
};


#endif // H_SQUARE_GRID_GENERATOR_H