#ifndef CONFIG_H
#define CONFIG_H

#include "descriptors/enums.h"
#include <cstdint>
#include <vector>

struct ConfigData {
	uint32_t size_x;
	uint32_t size_y;

	std::vector<GeneratorPass> orderedPases;
};

#endif // CONFIG_H
