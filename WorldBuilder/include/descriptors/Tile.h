#ifndef TILE_H
#define TILE_H

#include <cstdint>
#include <descriptors/enums.h>
#include <vector>

struct BaseInfo {
	uint64_t x;
	uint64_t y;
};

struct GroundInformation {
	int64_t elevation;
	std::vector<GroundTag> gtags;
};

struct Tile {
	BaseInfo base;
	GroundInformation ground_info;
};
#endif // TILE_H
