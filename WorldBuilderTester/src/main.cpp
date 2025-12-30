#include "descriptors/config.h"
#include "descriptors/enums.h"
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

	for (int i = 0; i < tileset.size(); i++)
	{
		for (int j = 0; j < tileset[i].size(); j++)
		{
			char character = '#';
			switch (tileset[i][j]->ground_info.gtags[0])
			{

			case GroundTag::Base:

				break;
			case GroundTag::Volcanic:
				character = '^';
				break;

			case GroundTag::Desert:
				character = '~';
				break;
			case GroundTag::Beach:
				character = '&';
				break;
			case GroundTag::Coral:
				character = '@';
				break;
			case GroundTag::BlackEarth:
				character = 'B';
				break;
			}
			outFile << character;
		}
		outFile << "\n";
	}
}
int main()
{

	std::unique_ptr<WorldBuilder> wb = std::make_unique<WorldBuilder>();

	std::vector<GeneratorPass> orderedPases{GeneratorPass::PoissonPlateStartersPopulation};
	ConfigData cd{100, 100, orderedPases};

	if (wb->configure(cd) == ErrorCode::Succes)
		std::cout << "configured" << std::endl;

	if (wb->Generate() == ErrorCode::Succes)
		std::cout << "Generated" << std::endl;

	saveTest(std::move(wb));
	return 0;
}
