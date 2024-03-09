#ifndef H_GENEREATOR_FACTORY_H
#define H_GENEREATOR_FACTORY_H

#include <configs/enums.h>

/* Future code for future dreams xD */
struct TectonicPlateCount
{
	int major_plates_count;
	int minor_plates_count;
};

int GetPlanetRadius(WorldPlanetType planet_type);
struct TectonicPlateCount GetPlanetTectonicPlatesCount(WorldPlanetType planet_type);

#endif // H_GENEREATOR_FACTORY_H