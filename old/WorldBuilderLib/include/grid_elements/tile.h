#ifndef H_TILE_H
#define H_TILE_H

/* This should use the concept of c-squares to represent the globe or standard squares
 * if the globe variable is off.
 * In first concept the higher the altitued of the square the more it should be influenced by
 * distant neighbours
 */

#include <configs/enums.h>
#include <cstdint>
#include <cstdlib>
#include <generators/tectonics/tectonic_plate.h>
#include <map>
#include <utils/calculations.h>

class Tile {
  public:
	Tile();
	Tile(uint32_t x, uint32_t y, uint32_t seed, Tile ***tileset, uint32_t size_x, uint32_t size_y);
	~Tile();

	Point coordinates;

	TileLevel level;
	TileType type;

	/* Size in meters
	 * top and bottom only used in specific case of c-squares
	 * TODO move c-square to separate class inheriting Tile if more than one additional c-square var
	 * is made
	 */
	uint32_t x_top_border_size; // maybe union for clarity ?
	uint32_t x_bottom_border_size;
	uint32_t y_border_size;

	/* Tile average altitude */
	int altitude;

	/* Tile temerature data */
	int temerature_avg;
	int temerature_lowest;
	int temerature_highest;

	/* Earth movments probability */
	uint32_t earth_move_event_probability;

	/* Decides if a tile type is more or less likley to show up near this one in generation time */
	std::map<TileType, int> tile_relations;

	/* Pointer to a tectonic plate */
	TectonicPlate *plate;
};

#endif // H_TILE_H