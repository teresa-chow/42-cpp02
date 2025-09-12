/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:08:50 by tchow-so          #+#    #+#             */
/*   Updated: 2025/09/12 17:01:42 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* BSP - Binary Space Partioning */

#include "Point.hpp"

/*  a, b, c are the vertices of a given triangle;
	point is a point that may or may not belong to said triangle
	
	return values:
	- true: point is inside the triangle
	- false: point is a vertex, edge or outside the triangle */

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	//pick an edge: AB BC or CA
	//form 2 vectors: AB and APoint
	//positive, negative or zero (on the line)
	//consistency triangle orientation (clockwise, for ex. - same side inside)
	return (true);
	//return (false);
}