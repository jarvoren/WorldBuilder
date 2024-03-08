#ifndef H_WORLD_H
#define H_WORLD_H

#include <cstring>
#include <grid_elements/tile.h>
#include <factories/generator_factory.h>
#include <configs/configs_agregator.h>

class World
{
public:
	World();
	ErrorCode Generate(WorldConfig* cfg);
	~World();
	void DestroyWorld(Tile*** tileset);

	/* Grid coordinates */
	WorldConfig world_config;
	/* De facto map saved in 2d array
	 * allocated by the generator
	 */
	Tile*** tileset;

	/* Gravity mulltiplier relative to earth gravity */
	int gravity;

	/* Globe merridian - for sake of simplicity it is just a circumference in meters */
	uint32_t globe_circumference;
};



#endif // H_WORLD_H