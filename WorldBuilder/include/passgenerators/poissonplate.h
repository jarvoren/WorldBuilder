#ifndef PASSION_PLATE_H
#define PASSION_PLATE_H

#include "passobject.h"

class PoissonPlate : public PassObject
{

	uint8_t major_plate_count;
	uint8_t minor_plate_count;

	uint32_t size_x;
	uint32_t size_y;

	void Configure(ConfigData &configuration) override;
	void RunPass(std::vector<std::vector<std::unique_ptr<Tile>>> &tileset) override;
};

#endif // PASSION_PLATE_H
