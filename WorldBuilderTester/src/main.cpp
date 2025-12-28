#include "descriptors/enums.h"
#include <WorldBuilder.h>
#include <fstream>
#include <iostream>
#include <memory>

int main() {
	std::ofstream outFile("map.txt");

	if (!outFile)
		return -1;
	std::vector<char> buffer(1024 * 1024);
	outFile.rdbuf()->pubsetbuf(buffer.data(), buffer.size());
	std::unique_ptr<WorldBuilder> wb = std::make_unique<WorldBuilder>();

	if (wb->configure(ConfigData()) == ErrorCode::Succes)
		std::cout << "configured" << std::endl;
	const auto &tileset = wb->GetTileset();
	for (int i = 0; i < tileset.size(); i++) {
		for (int j = 0; j < tileset[i].size(); j++) {
			char character = '#';
			switch (tileset[i][j]->ground_info.gtags[0]) {

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
	return 0;
}
