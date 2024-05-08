#ifndef H_WORLD_H
#define H_WORLD_H

#include <configs/configs_agregator.h>
#include <cstring>
#include <factories/generator_factory.h>
#include <grid_elements/tile.h>
#include <vector>

class World {
  public:
	World();
	ErrorCode Generate(WorldConfig *cfg);
	~World();
	void DestroyWorld(Tile ***tileset);

	WorldPlanetType planet_type;

	/* Grid coordinates */
	WorldConfig world_config;
	/* De facto map saved in 2d array
	 * allocated by the generator
	 */
	Tile ***tileset;

	std::vector<TectonicPlate *> tectonic_plates;

	/* Gravity mulltiplier relative to earth gravity */
	int gravity;

	/* Globe merridian - for sake of simplicity it is just a circumference in meters */
	uint32_t globe_circumference;
};

bool IsValidConfig(WorldConfig *cfg);

#endif // H_WORLD_H