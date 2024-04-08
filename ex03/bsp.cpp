#include "Point.hpp"

static float signedArea(Point const target, Point const other,
						Point const refpt) {
	return ((target.getX() - refpt.getX())
				* (other.getY() - refpt.getY())
			- (other.getX() - refpt.getX())
				  * (target.getY() - refpt.getY()));
}

/**
 * @brief Check if a point is inside a triangle (A, B, C)
 * @param point point to check
 * @return true if the point is inside the triangle
 * @return false if the point is outside the triangle (edge or vertex) 
 */
bool bsp(Point const pt_A, Point const pt_B, Point const pt_C,
		 Point const point) {
	float Area1 = signedArea(point, pt_A, pt_B);
	float Area2 = signedArea(point, pt_B, pt_C);
	float Area3 = signedArea(point, pt_C, pt_A);

	bool pos    = (Area1 > 0) || (Area2 > 0) || (Area3 > 0);
	bool zero   = (Area1 == 0) || (Area2 == 0) || (Area3 == 0);
	bool neg    = (Area1 < 0) || (Area2 < 0) || (Area3 < 0);

	return !(zero || (neg && pos));
}
