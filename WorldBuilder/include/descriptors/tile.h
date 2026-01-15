#ifndef TILE_H
#define TILE_H

#include "descriptors/plate.h"
#include <cstdint>
#include <descriptors/enums.h>
#include <memory>
#include <vector>

struct GroundInformation
{
	int64_t elevation;
	std::vector<GroundTag> gtags;
};

struct Tile
{
	PointInfo base;
	GroundInformation ground_info;
	std::shared_ptr<TectonicPlateInformation> tectonic_info;
};
#endif // TILE_H
