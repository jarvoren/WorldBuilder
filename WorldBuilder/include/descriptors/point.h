#ifndef POINT_H
#define POINT_H

#include <cstdint>

struct DirectionVector
{
	// only values for both should be 1 , 0 , -1
	uint8_t dx;
	uint8_t dy;
};

struct PointInfo
{
	uint64_t x;
	uint64_t y;

	PointInfo() {};
	PointInfo(uint64_t x, uint64_t y)
	{
		this->x = x;
		this->y = y;
	}
};

#endif // POINT_H
