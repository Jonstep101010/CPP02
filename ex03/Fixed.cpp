#include "Fixed.hpp"
#include <cmath> // for roundf
#include <iostream>

/* -------------------------------------------------------------------------- */
/*                          constructors/destructors                          */
/* -------------------------------------------------------------------------- */

/**
 * @brief default constructor
 */
Fixed::Fixed()
	: _value(0) {
	// std::cout << "Default constructor called\n";
}

/**
 * @brief copy constructor
 */
Fixed::Fixed(const Fixed& src)
	: _value(src.getRawBits()) { // is not necessary
	// std::cout << "Copy constructor called\n";
	*this = src;
}

/**
 * @brief Construct a new Fixed:: Fixed object (int)
 * @param raw int
 */
Fixed::Fixed(int const raw)
	: _value(raw << _fractionalBits) {
	// std::cout << "Int constructor called\n";
}

/**
 * @brief Construct a new Fixed:: Fixed object (float)
 * 
 * @param raw float
 */
Fixed::Fixed(float const raw)
	: _value(
		static_cast<int>(roundf(raw * (1 << _fractionalBits)))) {
	// std::cout << "Float constructor called\n";
}

Fixed::~Fixed() {}

/**
 * @brief copy assignment operator
 *
 * @param rhs
 * @return Fixed&
 */
Fixed& Fixed::operator=(Fixed const& rhs) {
	// std::cout << "Copy assignment operator called\n";
	if (this != &rhs) {
		_value = rhs.getRawBits();
	}
	return *this;
}

/* ---------------------------- getter and setter --------------------------- */

/**
 * @return int _value
 */
int Fixed::getRawBits() const {
	// std::cout << "getRawBits member function called\n";
	return (_value);
}

/**
 * @brief set _value to raw
 */
void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called\n";
	_value = raw;
}

/* -------------------------------------------------------------------------- */
/*                                  operators                                 */
/* -------------------------------------------------------------------------- */

/**
 * @brief Output operator overload to print Fixed object
 * @param o output stream
 * @param i Fixed object
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& o, Fixed const& i) {
	o << i.toFloat();
	return (o);
}

/* ------------------------------- comparisons ------------------------------ */

// const to avoid issues when used in const member functions
bool Fixed::operator>(Fixed const& b) const {
	return (this->getRawBits() > b.getRawBits());
}

bool Fixed::operator<(Fixed const& b) const {
	return (this->getRawBits() < b.getRawBits());
}

bool Fixed::operator>=(Fixed const& b) {
	return (this->getRawBits() >= b.getRawBits());
}

bool Fixed::operator<=(Fixed const& b) {
	return (this->getRawBits() >= b.getRawBits());
}

bool Fixed::operator==(Fixed const& b) {
	return (this->getRawBits() == b.getRawBits());
}

bool Fixed::operator!=(Fixed const& b) {
	return (this->getRawBits() != b.getRawBits());
}

/* ------------------------------- arithmetic ------------------------------- */

Fixed Fixed::operator+(Fixed const& b) {
	return (Fixed(this->toFloat() + b.toFloat()));
}

Fixed Fixed::operator-(Fixed const& b) {
	return (Fixed(this->toFloat() - b.toFloat()));
}

Fixed Fixed::operator*(Fixed const& b) {
	return (Fixed(this->toFloat() * b.toFloat()));
}

Fixed Fixed::operator/(Fixed const& b) {
	return (Fixed(this->toFloat() / b.toFloat()));
}

/* -------------------- increment and decrement operators ------------------- */

// pre increment, post increment, pre decrement, post decrement
// operate on fixed-point from smallest e (1 + e > 1)
// e.g. ++0 -> 0.00390625, ...

Fixed& Fixed::operator++() {
	++_value;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed copy(*this);

	++(*this);
	return (copy);
}

Fixed& Fixed::operator--() {
	--_value;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed copy(*this);

	--(*this);
	return (copy);
}

/* -------------------------------------------------------------------------- */
/*                                 conversions                                */
/* -------------------------------------------------------------------------- */

/**
 * @brief convert Fixed object integer to float
 * @return float representation of Fixed object
 */
float Fixed::toFloat() const {
	return (static_cast<float>(_value) / (1 << _fractionalBits));
}

/**
 * @brief convert Fixed object to integer
 * @return int integer representation of Fixed object
 */
int Fixed::toInt() const {
	return ((_value >> _fractionalBits));
}

/* -------------------------------------------------------------------------- */
/*                             overloaded members                             */
/* -------------------------------------------------------------------------- */

/**
 * @param a reference to Fixed object
 * @param b reference to Fixed object
 * @return Fixed& reference to smaller object
 */
Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b ? a : b); }

Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b ? a : b); }

/**
 * @param a reference to constant Fixed object
 * @param b reference to constant Fixed object 
 * @return Fixed& reference to smaller object
 */
const Fixed& Fixed::min(Fixed const& a, Fixed const& b) {
	return (a < b ? a : b);
}

const Fixed& Fixed::max(Fixed const& a, Fixed const& b) {
	return (a > b ? a : b);
}