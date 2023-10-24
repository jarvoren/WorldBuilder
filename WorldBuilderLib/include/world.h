#ifndef H_WORLD_H
#define H_WORLD_H

#include <stdio.h>
#include <cstdint>
#include <cstring>
#include <grid_elements/tile.h>
#include <generators/square_grid_generator.h>

enum TilesetType
{
	SQUARE,
	HEXAGONAL,
	FREE_DRAW, /* In far future the generation of enviroments with unusual borders may be added */
	TRIANGLE /* Probably never gonna see that comeing */
};

/* Config used to generate world 
 * if possible refrain from using pointers to anything as whole config will be copied
 * use identifiers that will use pointers later
 * Example: We want tilesets to be configurable. Maybe create existing characters. However
 * those would have to be created outside of config and either config needs to be its own
 * class with destructor to handle it or You need to be smart about how to handle it ;)
 * TO REMEMBER/TO DO
 */
struct WorldConfig
{
	/* Overworld grid size */
	uint32_t grid_x_size;
	uint32_t grid_y_size;

	/* Overworld grid type */
	TilesetType tile_type;

	/* Indicates if the generated world should encompass a globe or
	 * relativley flat surface. (important for generator adjecency )
	 */
	bool is_globe;
};

class World
{
public:
	World();
	World(WorldConfig* cfg);
	~World();
	void DestroyWorld(Tile*** tileset);

	/* Grid coordinates */
	WorldConfig world_config;
	/* De facto map saved in 2d array
	 * allocated by the generator
	 */
	Tile*** tileset;
private:

	

};



#endif // H_WORLD_H