#ifndef CONFIG_H
#define CONFIG_H

#include "descriptors/enums.h"
#include <cstdint>
#include <vector>

struct PlateTectonicsData
{
	// desired plate count - it will be subject to algorithm changes
	uint8_t major_plate_count;
	uint8_t minor_plate_count;
	uint8_t poisson_algorithm_retries;

	// The higher the multiplier is bigger amount of plates generated
	float poisson_algorithm_distance_multiplier = 1.3;

	uint32_t minDistanceOverrideMinor = 0;
	uint32_t minDistanceOverrideMajor = 0;
};
struct ConfigData
{
	uint32_t size_x;
	uint32_t size_y;

	uint32_t seed;

	PlateTectonicsData plateData;

	std::vector<GeneratorPass> orderedPases;
};

#endif // CONFIG_H
