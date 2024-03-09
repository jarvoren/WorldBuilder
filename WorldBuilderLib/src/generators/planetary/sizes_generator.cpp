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
	return planet_size;
}

struct TectonicPlateCount GetPlanetTectonicPlatesCount(WorldPlanetType planet_type)
{

	struct TectonicPlateCount tectonic_plates_count = { 0 };

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
		/* We asume 7 +- 2 */
		tectonic_plates_count.major_plates_count = 7 + rand() % 5 - 2;
		/* We asume 4 +- 1 */
		tectonic_plates_count.minor_plates_count = 4 + rand() % 2 - 1;
		break;
	case ISLAND:
		break;
	default:
		break;
	}
	return tectonic_plates_count;
}