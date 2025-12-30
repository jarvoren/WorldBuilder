#include <worldbuilder.h>

ErrorCode WorldBuilder::configure(const ConfigData &confData)
{
	ErrorCode retval = ErrorCode::Succes;
	return retval;
}

WorldBuilder::WorldBuilder() {}

WorldBuilder::~WorldBuilder() {}

const std::vector<std::vector<std::unique_ptr<Tile>>> &WorldBuilder::GetTileset()
{

	return this->tileset;
}

ErrorCode WorldBuilder::Generate()
{
	for (int i = 0; i < confData.orderedPases.size(); i++)
	{
		PassTranslator::GetPassObject(confData.orderedPases[i]);
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
		tileset.emplace_back(std::vector<std::unique_ptr<Tile>>());
		for (int j = 0; j < confData.size_y; j++)
		{

			std::unique_ptr<Tile> tile = std::make_unique<Tile>();
			tile->base.x = i;
			tile->base.y = j;

			tile->ground_info.gtags.push_back(static_cast<GroundTag>(distrib(gen)));

			tileset[i].push_back(std::move(tile));
		}
	}
}
