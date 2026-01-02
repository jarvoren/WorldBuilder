
#include "passgenerators/poissonplate.h"

void PoissonPlate::Configure(ConfigData &configuration)
{
	this->minor_plate_count = configuration.minor_plate_count;
	this->major_plate_count = configuration.major_plate_count;

	this->size_x = configuration.size_x;
	this->size_y = configuration.size_y;
}
void PoissonPlate::RunPass(std::vector<std::vector<std::unique_ptr<Tile>>> &tileset) {}
