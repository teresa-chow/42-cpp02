/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:09:38 by tchow-so          #+#    #+#             */
/*   Updated: 2025/09/12 12:10:15 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ******************* Default & parametrized constructors ****************** */
Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y)  : _x(x), _y(y) {}

/* **************************** Copy constructor **************************** */
Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

/* ********************** Assignment operator overload ********************** */
Point& Point::operator = (const Point& other) {}

/* ******************************* Destructor ******************************* */
Point::~Point() {}