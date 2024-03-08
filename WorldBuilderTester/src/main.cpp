#include <main.h>

int main()
{
	WorldConfig* new_cfg = new WorldConfig();
	new_cfg->grid_x_size = 60;
	new_cfg->grid_y_size = 60;
	new_cfg->tileset_configuration = SQUARE;

	World* myworld = new World();
	myworld->Generate(new_cfg);

	for (size_t i = 0; i < myworld->world_config.grid_x_size; i++)
	{
		for (size_t j = 0; j < myworld->world_config.grid_y_size; j++)
		{
			switch (myworld->tileset[i][j]->type)
			{
			case WATER:
				printf("~");
				break;
			case LANDMASS:
				printf("w");
				break;
			case MOUNTAIN:
				printf("^");
				break;
			default:
				break;
			}
			
			if (j + 1 == myworld->world_config.grid_y_size) printf("\n");
		}
	}

	getchar();
	return 0;
}