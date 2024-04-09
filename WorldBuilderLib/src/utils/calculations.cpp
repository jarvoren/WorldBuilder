#include <utils\calculations.h>


int GetRoundedDistance(Point point_one, Point point_two)
{
	return sqrt(pow(point_two.pos_x - point_one.pos_x, 2) + pow(point_two.pos_y - point_one.pos_y, 2));
}
