#ifndef WORLD_BUILDER_H
#define WORLD_BUILDER_H

#include "descriptors/enums.h"
#include "passgenerators/passtranslator.h"
#include <cstdint>
#include <descriptors/config.h>
#include <descriptors/tile.h>
#include <memory>
#include <random>

class WorldBuilder
{
  private:
	ConfigData confData;

	std::vector<Tile> tileset;

  public:
	// Rule of 5
	WorldBuilder();
	~WorldBuilder();
	WorldBuilder(const WorldBuilder &other) = delete;
	WorldBuilder &operator=(const WorldBuilder &other) = delete;
	WorldBuilder(WorldBuilder &&other) noexcept = delete;
	WorldBuilder &operator=(WorldBuilder &&other) noexcept = delete;

	ErrorCode Generate();
	ErrorCode Save();
	void Test();
	ErrorCode configure(const ConfigData &confData);
	const std::vector<Tile> &GetTileset();

	uint64_t GetConfiguredx() { return confData.size_x; }
	uint64_t GetConfiguredY() { return confData.size_y; }
};

#endif // WORLD_BUILDER_H
