#include "Point.hpp"
#include <iostream>

static void test_bsp(Point a, Point b, Point c, Point p) {
	a.printPoint("A");
	b.printPoint("B");
	c.printPoint("C");
	p.printPoint("P");
	if (!bsp(a, b, c, p)) {
		std::cout
			<< "\033[31mPoint is not in the triangle\033[0m\n";
	} else {
		std::cout << "\033[32mPoint is in the triangle\033[0m\n";
	}
}

int main() {
	// point in a triangle
	test_bsp(Point(0, 0), Point(10, 0), Point(0, 10),
			 Point(0.01, 0.01));

	// point not in a triangle
	test_bsp(Point(0, 0), Point(10, 0), Point(0, 10),
			 Point(11, 0.01));

	// point is vertex of a triangle
	test_bsp(Point(10, 10), Point(10, 11), Point(10, 12),
			 Point(10, 11));

	// point is on the edge of a triangle
	test_bsp(Point(0, 0), Point(10, 0), Point(0, 10),
			 Point(5, 0));
	return 0;
}
