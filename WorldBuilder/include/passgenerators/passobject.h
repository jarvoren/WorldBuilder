#ifndef PASS_OBJECT_H
#define PASS_OBJECT_H

#include "descriptors/config.h"
#include "descriptors/tile.h"
#include <memory>

class PassObject
{
  public:
	virtual ~PassObject() = default;
	virtual void Configure(ConfigData &configuration) = 0;
	virtual void RunPass(std::vector<std::vector<std::unique_ptr<Tile>>> &tileset) = 0;
};

#endif // PASS_OBJECT_H
