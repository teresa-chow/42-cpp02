/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:36:12 by tchow-so          #+#    #+#             */
/*   Updated: 2025/09/12 11:45:19 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed {
	public:
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static	Fixed& min(Fixed& n1, Fixed& n2);
		static	const Fixed& min(const Fixed& n1, const Fixed& n2);
		static	Fixed& max(Fixed& n1, Fixed& n2);
		static	const Fixed& max(const Fixed& n1, const Fixed& n2);
	
		Fixed();
		Fixed(const int integer);
		Fixed(const float floatingPoint);
		Fixed(const Fixed& other);
		
		Fixed& operator = (const Fixed& other);
		// Comparison operators overload
		bool operator > (const Fixed& other) const;
		bool operator < (const Fixed& other) const;
		bool operator >= (const Fixed& other) const;
		bool operator <= (const Fixed& other) const;
		bool operator == (const Fixed& other) const;
		bool operator != (const Fixed& other) const;
		// Arithmetic operators overeload
		Fixed operator + (const Fixed& other) const;
		Fixed operator - (const Fixed& other) const;
		Fixed operator * (const Fixed& other) const;
		Fixed operator / (const Fixed& other) const;
		// Increment and decrement operators overload
		float operator ++ ();
		float operator -- ();
		float operator ++ (int); // postfix : (int) is dummy param
		float operator -- (int);
		
		~Fixed();
	
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& src);

#endif