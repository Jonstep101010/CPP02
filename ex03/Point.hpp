#pragma once

#include "Fixed.hpp"

class Point {

public:
	Point();
	Point(float x, float y);
	Point(Point const& src);
	Point& operator=(Point const& rhs);
	~Point();
	float getX() const;
	float getY() const;

private:
	const Fixed x;
	const Fixed y;
	//...
};

bool bsp(Point const a, Point const b, Point const c,
		 Point const point);