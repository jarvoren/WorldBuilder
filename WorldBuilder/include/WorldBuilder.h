#ifndef WORLD_BUILDER_H
#define WORLD_BUILDER_H

#include <descriptors/Tile.h>
#include <descriptors/config.h>

class WorldBuilder {
  private:
	ConfigData confData;

  public:
	ErrorCode configure(const ConfigData &confData);
};

#endif // WORLD_BUILDER_H
