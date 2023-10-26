#include <factories/generator_factory.h>

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