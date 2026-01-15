#include "descriptors/enums.h"
#include "utilities/rng.h"
#include <worldbuilder.h>

ErrorCode WorldBuilder::configure(const ConfigData &confData)
{
	ErrorCode retval = ErrorCode::Succes;

	this->confData = confData;
	this->tileset.resize(confData.size_x * confData.size_y);

	for (int i = 0; i < confData.size_x; i++)
	{
		for (int j = 0; j < confData.size_y; j++)
		{
			Tile tile;
			tile.base.x = i;
			tile.base.y = j;

			tile.ground_info.gtags.push_back(static_cast<GroundTag>(
				RandomUint64(1, static_cast<uint64_t>(GroundTag::Last) - 1)));

			tileset[i * confData.size_x + j] = tile;
		}
	}

	RandomGenerator::getInstance().SetSeed(confData.seed);

	return retval;
}

WorldBuilder::WorldBuilder() {}

WorldBuilder::~WorldBuilder() {}

const std::vector<Tile> &WorldBuilder::GetTileset() { return this->tileset; }

ErrorCode WorldBuilder::Generate()
{
	for (int i = 0; i < confData.orderedPases.size(); i++)
	{
		auto pass = PassTranslator::GetPassObject(confData.orderedPases[i]);
		pass->Configure(this->confData);
		pass->RunPass(this->tileset);
	}
	return ErrorCode::Succes;
}

ErrorCode WorldBuilder::Save() { return ErrorCode::Succes; }

void WorldBuilder::Test()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(1, static_cast<int>(GroundTag::BlackEarth));

	confData.size_x = 100;
	confData.size_y = 100;

	for (int i = 0; i < confData.size_x; i++)
	{
		for (int j = 0; j < confData.size_y; j++)
		{
			Tile tile;
			tile.base.x = i;
			tile.base.y = j;

			tile.ground_info.gtags.push_back(static_cast<GroundTag>(distrib(gen)));

			tileset.push_back(std::move(tile));
		}
	}
}
