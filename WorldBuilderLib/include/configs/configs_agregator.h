#ifndef H_CONFIGS_AGREGATOR_H
#define H_CONFIGS_AGREGATOR_H

#include <cstdint>
#include <grid_elements/tile.h>

/* This file should agregate all config structs that are generic enough */

struct GenerationConfig
{
	uint32_t poisson_retry_count;
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
	/* Only values divisible by 2 for these sizes in valid config */

	/* Horizontal squares count */
	uint32_t grid_x_size;
	/* Vertical squares count */
	uint32_t grid_y_size;

	/* Overworld grid type */
	TilesetType tileset_configuration;

	/* Indicates if the generated world should encompass a globe or
	* relativley flat surface. (important for generator adjecency )
	*/
	bool is_globe;

	GenerationConfig generator_config;
	/* Tile size in m allows configuring tile size for
	 * generator
	 */
	uint32_t tile_size = 1000;

	/* Type of planet that will be generated */
	WorldPlanetType planet_type;

	uint32_t seed;
};


#endif // H_CONFIGS_AGREGATOR_H