#ifndef H_TECTONIC_PLATE_H
#define H_TECTONIC_PLATE_H

#include <cstdint>

enum TectonicPlateType
{
	OCEANIC,
	CONTINENTAL
};


class TectonicPlate
{
public:
	TectonicPlate();
	~TectonicPlate();

	uint32_t density;
	TectonicPlateType type;
};

TectonicPlate::TectonicPlate()
{
	density = 0;
	type = OCEANIC;
}

TectonicPlate::~TectonicPlate()
{
}

#endif // H_TECTONIC_PLATE_H