/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:10:02 by tchow-so          #+#    #+#             */
/*   Updated: 2025/09/12 17:52:26 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point {
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& other);

		/* const members force construction-time initialization only
		(c++11 forward):
		Point& operator = (const Point& other) = delete; */
		Point& operator = (const Point& other);

		~Point();
	
	private:
		const Fixed _x;
		const Fixed _y;
};

struct	Vector {
	Fixed	dx;
	Fixed	dy;
	Vector(Fixed x = 0, Fixed y = 0) : dx(x), dy(y) {}
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif