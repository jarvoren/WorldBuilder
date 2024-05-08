#include <utils\poisson_calculation.h>

Point GetPoissonPointPositiveOnly(Point starting_point, int max_radius, int min_radius) {
	Point ret_val;

	double random_double = static_cast<double>(rand()) / RAND_MAX;
	double angle = 2 * M_PI * random_double;

	double radius = min_radius + (rand() % (max_radius - min_radius));

	/* I dont like this place, reeks of problems with casting radius* cos or sin can produce
	 * negatives rethink if possible
	 */
	ret_val.pos_y = abs(starting_point.pos_y + radius * std::sin(angle));
	ret_val.pos_x = abs(starting_point.pos_x + radius * std::cos(angle));

	return ret_val;
}

ErrorCode ValidatePoint(std::vector<Point> *saved_points, Point point_to_validate, int max_x,
						int max_y, int min_distance) {

	if (point_to_validate.pos_x > max_x || point_to_validate.pos_y > max_y)
		return ERR_POINT_OUTSIDE_OF_MAXIMUM_RANGE;

	for (int i = 0; i < saved_points->size(); i++) {
		if (GetRoundedDistance(saved_points->at(i), point_to_validate) < min_distance) {
			return ERR_POINTS_TOO_CLOSE_TO_EACH_OTHER;
		}
	}

	return ERR_SUCCESS;
}
