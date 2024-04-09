#ifndef H_CALCULATIONS_H
#define H_CALCULATIONS_H

#include <cmath>
#include <cstdint>

struct Point
{
	int pos_x;
	int pos_y;
};

int GetRoundedDistance(Point point_one, Point point_two);

#endif // H_CALCULATIONS_H