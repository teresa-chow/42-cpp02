/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:36:07 by tchow-so          #+#    #+#             */
/*   Updated: 2025/09/11 12:26:35 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int integer) {
	std::cout << "Int constructor called\n";
	_rawBits = integer << _fractionalBits;
}

Fixed::Fixed(const float floatingPoint) {
	std::cout << "Float constructor called\n";
	_rawBits = static_cast<int>(roundf(floatingPoint * (1 << _fractionalBits)));
	std::cout << "debug: " << _rawBits << std::endl;
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed &Fixed::operator=(const Fixed& src) {
	std::cout << "Copy assignment operator called\n";
	if (this != &src)
		_rawBits = src._rawBits;
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

float	Fixed::toFloat( void ) const {
	return (static_cast<float>(_rawBits) / (1 << _fractionalBits));
}

int		Fixed::toInt( void ) const {
	return (_rawBits >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& src) {
	os << (src.toFloat());
	return (os);
}