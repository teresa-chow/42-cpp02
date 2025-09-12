/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:36:12 by tchow-so          #+#    #+#             */
/*   Updated: 2025/09/12 10:42:34 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	public:
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;
	
		Fixed();
		Fixed(const int integer);
		Fixed(const float floatingPoint);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
	
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& src);

#endif