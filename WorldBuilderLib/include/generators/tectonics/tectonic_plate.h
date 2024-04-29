#ifndef H_TECTONIC_PLATE_H
#define H_TECTONIC_PLATE_H

#include <cstdint>
#include <configs/enums.h>

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

	TectonicPlateType type;
	NumpadDirections direction;

	/* Plate density used for interaction calculations */
	uint32_t density;
	/* Maximum amout of tiles */
	uint8_t max_size;
	/* Is plate major - needed for generation purposes */
	bool is_major;
};


#endif // H_TECTONIC_PLATE_H