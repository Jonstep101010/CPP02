#include "Fixed.hpp"
#include <iostream>

/**
 * @brief default constructor
 */
Fixed::Fixed()
	: _value(0) {
	std::cout << "Default constructor called\n";
}

/**
 * @brief copy constructor
 */
Fixed::Fixed(const Fixed& src)
	: _value(0) {
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed::~Fixed() { std::cout << "Destructor called\n"; }

/**
 * @brief copy assignment operator
 *
 * @param rhs
 * @return Fixed&
 */
Fixed& Fixed::operator=(Fixed const& rhs) {
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs) {
		_value = rhs.getRawBits();
	}
	return *this;
}

/**
 * @return int _value
 */
int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return (_value);
}

/**
 * @brief set _value to raw
 */
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	_value = raw;
}
