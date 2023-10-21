#ifndef H_WORLD_H
#define H_WORLD_H

#include <stdio.h>
#include <cstdint>

class WorldDescriptor
{
public:
	WorldDescriptor();
	~WorldDescriptor();

private:
	bool isSquareGrid;
	uint32_t gridHeight;
	uint32_t gridLength;
	Tile

};

WorldDescriptor::WorldDescriptor()
{
	isSquareGrid = true;
	gridHeight = 0;
	gridLength = 0;
}

WorldDescriptor::~WorldDescriptor()
{
}
void test_lib();

#endif // H_WORLD_H