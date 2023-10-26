#ifndef H_TILE_H
#define H_TILE_H

/* This should use the concept of c-squares to represent the globe or standard squares
 * if the globe variable is off.
 * In first concept the higher the altitued of the square the more it should be influenced by distant neighbours
 */

#include <cstdint>
#include <cstdlib>
#include <configs/enums.h>

class Tile
{
public:
	Tile();
	Tile(uint32_t x, uint32_t y, uint32_t seed, Tile*** tileset, uint32_t size_x, uint32_t size_y);
	~Tile();

	uint32_t pos_x;
	uint32_t pos_y;

	TileLevel level;
	TileType type;

private:

};


#endif // H_TILE_H