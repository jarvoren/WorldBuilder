#include <factories/generator_factory.h>
#include <generators/square_grid_generator.h>

Generator* GeneratorFactory(WorldConfig* cfg)
{
	switch (cfg->tileset_configuration)
	{
		case SQUARE:
		{
			return new SquareGridGenerator(cfg);
			break;
		}
	}
	return NULL;
}