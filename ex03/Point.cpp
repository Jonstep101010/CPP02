#include "Point.hpp"
#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point()
	: x(0), y(0) {}

Point::Point(const Point& src)
	: x(src.x), y(src.y) {
	if (this != &src) {
		*this = src;
	}
}

Point::Point(float const x, float const y)
	: x(x), y(y) {}

Point& Point::operator=(Point const& rhs) {
	(void)rhs;
	return *this;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point() {}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Point::printPoint(std::string prefix) const {
	std::cout << prefix << "(x: " << getX() << "; y: " << getY()
			  << ")\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

float Point::getX(void) const { return x.toFloat(); }

float Point::getY(void) const { return y.toFloat(); }

/* ************************************************************************** */