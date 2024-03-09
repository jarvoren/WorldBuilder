#include <world.h>

void World::DestroyWorld(Tile*** tileset)
{
	/* Free the tileset */
	/* TODO Check if the tiles do not need any pointers freed */
	for (size_t i = 0; i < world_config.grid_x_size; i++)
	{
		for (size_t j = 0; j < world_config.grid_y_size; j++)
		{
			delete tileset[i][j];
		}
		delete[] tileset[i];
	}
	delete[] tileset;
}

/* Config will be copied and can be disposed by caller afterwards */
ErrorCode World::Generate(WorldConfig* cfg)
{
	if (IsValidConfig(cfg))
		return ERR_ILLEGAL_CONFIG_DATA;

	srand(cfg->seed);

	/* Copy the config to the world object */
	std::memcpy(&world_config, cfg, sizeof(WorldConfig));

	//TODO Generate basic tileset
	Generator* tileset_generator = GeneratorFactory(&world_config);

	/* DEBUG to remove afterwards */
	//tileset = tileset_generator->GenerateTestTileset(world_config.grid_x_size, world_config.grid_y_size);

	//TODO Populate the tileset with proper tiles - terrain only generation
	tileset = tileset_generator->GeneratePlanetsTileset();

	//TODO Generate populace, main characters and factions		**together** ??
	//															**together** ??
	//TODO Populate the tiles with places (start of history)	**together** ??

	//TODO Generate History of the world
}


World::World()
{
	world_config = { 0 };
	tileset = NULL;
	planet_type = EARTH;
	gravity = 1;
}

World::~World()
{
}

/* Returns true on valid config */
bool IsValidConfig(WorldConfig* cfg)
{
	/* grid size must be divisible by 2 for generator */
	if (cfg->grid_x_size % 2 || cfg->grid_y_size % 2)
		return false;

	return true;
}