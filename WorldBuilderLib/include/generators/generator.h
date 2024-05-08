#ifndef H_GRID_GENERATOR_H
#define H_GRID_GENERATOR_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <configs/configs_agregator.h>
#include <grid_elements/tile.h>
#include <utils/calculations.h>
#include <vector>

class Generator {
  public:
	virtual Tile ***GeneratePlanetsTileset() = 0;
	virtual Tile ***GenerateTestTileset(uint32_t x_size, uint32_t y_size) = 0;
	virtual std::vector<TectonicPlate *> GetTectonicPlates() = 0;

	WorldConfig *world_cfg_ptr;
	std::vector<TectonicPlate *> created_plates;
	Tile ***generator_tileset;
};

#endif // H_GRID_GENERATOR_H