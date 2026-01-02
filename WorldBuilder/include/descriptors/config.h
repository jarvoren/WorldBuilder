#ifndef CONFIG_H
#define CONFIG_H

#include "descriptors/enums.h"
#include <cstdint>
#include <vector>

struct ConfigData
{
	uint32_t size_x;
	uint32_t size_y;

	uint8_t major_plate_count;
	uint8_t minor_plate_count;

	std::vector<GeneratorPass> orderedPases;
};

#endif // CONFIG_H
