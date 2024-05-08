#ifndef H_SQUARE_GRID_GENERATOR_H
#define H_SQUARE_GRID_GENERATOR_H

/* This should use the concept of c-squares to represent the globe or standard squares
 * if the globe variable is off.
 */

#include <utils\poisson_calculation.h>
#include <generators\generator.h>
#include <generators\planetary\sizes_generator.h>

#define RADIUS_DIVIDER 3

class SquareGridGenerator : public Generator
{
public:
	SquareGridGenerator(WorldConfig* cfg);
	Tile*** GeneratePlanetsTileset() override;
	Tile*** GenerateTestTileset(uint32_t x_size, uint32_t y_size) override;
	Tile*** GenerateBasicTileset(uint32_t x_size, uint32_t y_size);
	std::vector<TectonicPlate*> GetTectonicPlates();
private:
	void GenerateAndSaveNewTectonicPlates(std::vector<Point> saved_points, bool is_major);
	void PopulateGridWithTectonicStartPoints();
	void ExpandPlatePoints();
	std::vector<Point> GetPlateCoordinates(int plate_count, int max_radius, int min_radius);
};


#endif // H_SQUARE_GRID_GENERATOR_H