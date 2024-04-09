#ifndef H_POISSON_CALCULATIONS_H
#define H_POISSON_CALCULATIONS_H

#define _USE_MATH_DEFINES

#include <utils\calculations.h>
#include <configs\enums.h>
#include <vector>


Point GetPoissonPointPositiveOnly(Point starting_point, int max_radius, int min_radius);
ErrorCode ValidatePoint(std::vector<Point>* saved_points, Point point_to_validate, int max_x, int max_y, int min_distance);
#endif // H__POISSON_CALCULATIONS_H