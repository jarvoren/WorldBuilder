#ifndef WORLD_BUILDER_H
#define WORLD_BUILDER_H

#include <descriptors/Tile.h>
#include <descriptors/config.h>
#include <memory>
#include <random>

class WorldBuilder {
  private:
	ConfigData confData;
	std::vector<std::vector<std::unique_ptr<Tile>>> tileset;

  public:
	// Rule of 5
	WorldBuilder();
	~WorldBuilder();
	WorldBuilder(const WorldBuilder &other) = delete;
	WorldBuilder &operator=(const WorldBuilder &other) = delete;
	WorldBuilder(WorldBuilder &&other) noexcept = delete;
	WorldBuilder &operator=(WorldBuilder &&other) noexcept = delete;

	ErrorCode configure(const ConfigData &confData);
	const std::vector<std::vector<std::unique_ptr<Tile>>> &GetTileset();
};

#endif // WORLD_BUILDER_H
