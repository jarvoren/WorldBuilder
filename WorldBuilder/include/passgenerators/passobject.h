#ifndef PASS_OBJECT_H
#define PASS_OBJECT_H

#include "descriptors/config.h"
#include "descriptors/enums.h"
#include "descriptors/tile.h"
#include <memory>

class PassObject
{
  public:
	virtual ~PassObject() = default;
	virtual ErrorCode Configure(ConfigData &configuration) = 0;
	virtual ErrorCode RunPass(std::vector<Tile> &tileset) = 0;
};

#endif // PASS_OBJECT_H
