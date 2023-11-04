#include <generators/planetary/sizes_generator.h>

/* Get planet radius size in meters */
int GetPlanetRadius(WorldPlanetType planet_type)
{
	int planet_size = 0;

	switch (planet_type)
	{
	case CARBON:
		break;
	case CORELESS:
		break;
	case DESERT:
		break;
	case DWARF:
		break;
	case EGGSHELL:
		break;
	case HYCEAN:
		break;
	case ICE:
		break;
	case IRON:
		break;
	case LAVA:
		break;
	case OCEAN:
		break;
	case EARTH:
		planet_size = 6371000; //google earth data
		break;
	case ISLAND:
		break;
	default:
		break;
	}
}