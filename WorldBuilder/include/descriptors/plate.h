#ifndef TECTONIC_PLATE_H
#define TECTONIC_PLATE_H

#include "descriptors/point.h"
#include <descriptors/enums.h>
#include <vector>

struct TectonicPlateInformation
{
	uint64_t origin_x = 0;
	uint64_t origin_y = 0;
	PlateDensity density;
	DirectionVector plate_direction;
	PlateType type;
};

#endif // TECTONIC_PLATE_H
