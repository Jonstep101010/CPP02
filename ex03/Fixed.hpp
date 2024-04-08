#pragma once

# include <iostream>

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

	// comparison
	bool operator>(Fixed const& b) const;
	bool operator<(Fixed const& b) const;
	bool operator>=(Fixed const& b);
	bool operator<=(Fixed const& b);
	bool operator==(Fixed const& b);
	bool operator!=(Fixed const& b);

	// arithmetic
	Fixed operator+(Fixed const &b);
	Fixed operator-(Fixed const &b);
	Fixed operator*(Fixed const &b);
	Fixed operator/(Fixed const &b);

	// increment/decrement
	Fixed& operator++();
	Fixed  operator++(int);
	Fixed& operator--();
	Fixed  operator--(int);

	// overloaded static members
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(Fixed const& a, Fixed const& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(Fixed const& a, Fixed const& b);

private:
	int              _value;
	static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& o, Fixed const& i);
