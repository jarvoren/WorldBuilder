#ifndef H_CALCULATIONS_H
#define H_CALCULATIONS_H

#include <cstdint>

struct Point
{
	uint32_t pos_x;
	uint32_t pos_y;
};

int GetRoundedDistance(Point point_one, Point point_two);

#endif // H_CALCULATIONS_H