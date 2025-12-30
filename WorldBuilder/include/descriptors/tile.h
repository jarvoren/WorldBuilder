#ifndef TILE_H
#define TILE_H

#include <cstdint>
#include <descriptors/enums.h>
#include <memory>
#include <vector>

struct BaseInfo {
	uint64_t x;
	uint64_t y;
};

struct GroundInformation {
	int64_t elevation;
	std::vector<GroundTag> gtags;
};

struct DirectionVector {
	// only values for both should be 1 , 0 , -1
	uint8_t dx;
	uint8_t dy;
};
struct TectonicPlateInformation {
	uint64_t origin_x;
	uint64_t origin_y;
	PlateDensity density;
	DirectionVector plate_direction;
};

struct Tile {
	BaseInfo base;
	GroundInformation ground_info;
	std::shared_ptr<TectonicPlateInformation> tectonic_info;
};
#endif // TILE_H
