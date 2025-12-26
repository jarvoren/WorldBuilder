#ifndef TILE_H
#define TILE_H

#include <cstdint>
#include <vector>
#include <descriptors/enums.h>

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
};
#endif // TILE_H
