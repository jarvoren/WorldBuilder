#include <world.h>

void test_lib()
{
	printf("goo");
}


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

World::World(WorldConfig* cfg)
{
	std::memcpy(&world_config, cfg, sizeof(WorldConfig));
	tileset = GenerateTileset(world_config.grid_x_size, world_config.grid_y_size);
}


World::World()
{
	world_config = {0};
	tileset = NULL;
}

World::~World()
{
}
