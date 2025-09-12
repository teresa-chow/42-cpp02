/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:36:07 by tchow-so          #+#    #+#             */
/*   Updated: 2025/09/12 09:08:23 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************** Default constructor ************************** */
Fixed::Fixed() : _rawBits(0) {}

/* *********************** Parametrized constructors *********************** */
Fixed::Fixed(const int integer) {
	_rawBits = integer << _fractionalBits;
}
Fixed::Fixed(const float floatingPoint) {
	_rawBits = static_cast<int>(roundf(floatingPoint * (1 << _fractionalBits)));
}

/* *************************** Copy constructor *************************** */
Fixed::Fixed(const Fixed& other) {
	*this = other;
}

/* ************************** Operators overload ************************** */
Fixed& Fixed::operator = (const Fixed& other) {
	if (this != &other)
		_rawBits = other._rawBits;
	return (*this);
}
// Comparison operators
bool Fixed::operator > (const Fixed& other) const {
	return (this->_rawBits > other._rawBits);
}
bool Fixed::operator < (const Fixed& other) const {
	return (this->_rawBits < other._rawBits);	
}
bool Fixed::operator >= (const Fixed& other) const {
	return (this->_rawBits >= other._rawBits);	
}
bool Fixed::operator <= (const Fixed& other) const {
	return (this->_rawBits <= other._rawBits);
}
bool Fixed::operator == (const Fixed& other) const {
	return (this->_rawBits == other._rawBits);
}
bool Fixed::operator != (const Fixed& other) const {
	return (this->_rawBits != other._rawBits);
}

// Arithmetic operators
Fixed Fixed::operator + (const Fixed& other) const {
	Fixed	sum;
	sum._rawBits = this->_rawBits + other._rawBits;
	return (sum);
}
Fixed Fixed::operator - (const Fixed& other) const {
	Fixed	diff;
	diff._rawBits = this->_rawBits - other._rawBits;
	return (diff);
}
Fixed Fixed::operator * (const Fixed& other) const {
	Fixed	product(this->toFloat() * other.toFloat());
	return (product);
}
Fixed Fixed::operator / (const Fixed& other) const {
	Fixed	quotient(this->toFloat() / other.toFloat());
	return (quotient);
}

/*
epsilon :
	smallest step in number system,
		the difference between 2 consecutive representable values.
	For 8 fractional bits -> 1/(2^8) = 1/256 = 0.00390625 */
// prefix
float Fixed::operator ++ () {
	float floatValue = toFloat();
	floatValue += 0.00390625;
	_rawBits = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
	return (floatValue);
}
float Fixed::operator -- () {
	float floatValue = toFloat();
	floatValue -= 0.00390625;
	_rawBits = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
	return (floatValue);
}
// postfix
float Fixed::operator ++ (int) {
	float floatValue = toFloat();
	float floatInc = floatValue + 0.00390625;
	_rawBits = static_cast<int>(roundf(floatInc * (1 << _fractionalBits)));
	return (floatValue);
}
float Fixed::operator -- (int) {
	float floatValue = toFloat();
	float floatDec = floatValue - 0.00390625;
	_rawBits = static_cast<int>(roundf(floatDec * (1 << _fractionalBits)));
	return (floatValue);
}

/* ***************************** Destructor ***************************** */
Fixed::~Fixed() {}

/* ************************** Member functions ************************* */
float	Fixed::toFloat( void ) const {
	return (static_cast<float>(_rawBits) / (1 << _fractionalBits));
}

int		Fixed::toInt( void ) const {
	return (_rawBits >> _fractionalBits);
}

/* ************************* Functions overload ************************ */
Fixed& Fixed::min(Fixed& n1, Fixed& n2) {
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}
const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2) {
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}
Fixed& Fixed::max(Fixed& n1, Fixed& n2) {
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}
const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2) {
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}

/* ******************* Overload of insertion operator ****************** */
std::ostream& operator<<(std::ostream& os, const Fixed& src) {
	os << src.toFloat();
	return (os);
}