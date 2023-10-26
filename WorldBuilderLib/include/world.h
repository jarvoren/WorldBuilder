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