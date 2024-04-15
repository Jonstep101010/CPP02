#pragma once

#include <iostream>

class Fixed {
public:
	Fixed();
	Fixed(int const raw);
	Fixed(float const raw);
	Fixed(Fixed const& src);
	~Fixed();

	Fixed& operator=(Fixed const& rhs);
	int    getRawBits() const;
	void   setRawBits(int const raw);
	float  toFloat() const;
	int    toInt() const;

private:
	int              _value;
	static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& o, Fixed const& i);
