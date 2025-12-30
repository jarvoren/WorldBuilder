#ifndef PASSION_PLATE_H
#define PASSION_PLATE_H

#include "passobject.h"

class PoissonPlate : public PassObject
{
	void Configure(ConfigData configuration) override;
	void RunPass(std::vector<std::vector<std::unique_ptr<Tile>>> &tileset) override;
};

#endif // PASSION_PLATE_H
