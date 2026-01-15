#include "descriptors/config.h"
#include "descriptors/enums.h"
#include "utilities/rng.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <worldbuilder.h>

void saveTest(std::unique_ptr<WorldBuilder> wb)
{
	std::ofstream outFile("map.txt");

	if (!outFile)
		return;
	std::vector<char> buffer(1024 * 1024);
	outFile.rdbuf()->pubsetbuf(buffer.data(), buffer.size());
	const auto &tileset = wb->GetTileset();

	for (int i = 0; i < tileset.size() / wb->GetConfiguredY(); i++)
	{
		for (int j = 0; j < wb->GetConfiguredY(); j++)
		{
			char character = '#';
			// switch (tileset[i * wb->GetConfiguredY() + j].ground_info.gtags[0])
			// {
			//
			// case GroundTag::Base:
			//
			// 	break;
			// case GroundTag::Volcanic:
			// 	character = '^';
			// 	break;
			//
			// case GroundTag::Desert:
			// 	character = '~';
			// 	break;
			// case GroundTag::Beach:
			// 	character = '&';
			// 	break;
			// case GroundTag::Coral:
			// 	character = '@';
			// 	break;
			// case GroundTag::BlackEarth:
			// 	character = 'B';
			// 	break;
			// }
			if (tileset[i * wb->GetConfiguredY() + j].tectonic_info &&
				tileset[i * wb->GetConfiguredY() + j].tectonic_info->origin_x)
			{
				character = 'P';
				log_info("Char p dla plyty");
			}
			outFile << character;
		}
		outFile << "\n";
	}
}
int main()
{
	RandomGenerator::getInstance().SetSeed(100);

	std::unique_ptr<WorldBuilder> wb = std::make_unique<WorldBuilder>();

	std::vector<GeneratorPass> orderedPases{GeneratorPass::PoissonPlateStartersPopulation};
	ConfigData cd;

	cd.orderedPases = orderedPases;
	cd.size_x = 100;
	cd.size_y = 100;
	cd.plateData.minor_plate_count = 6;
	cd.plateData.major_plate_count = 6;
	cd.plateData.poisson_algorithm_retries = 30;

	if (wb->configure(cd) == ErrorCode::Succes)
		std::cout << "configured" << std::endl;

	if (wb->Generate() == ErrorCode::Succes)
		std::cout << "Generated" << std::endl;

	saveTest(std::move(wb));
	return 0;
}
