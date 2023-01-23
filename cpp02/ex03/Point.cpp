/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:13:51 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/22 21:07:16 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0) { }

Point::Point(float const x, float const y): _x(x), _y(y) { }

Point::Point(Point const& point) {
	*this = point;
}

Point& Point::operator=(Point const& point) {
	if (this != &point)
	{
		(Fixed&)(this->_x) = point.getX();
		const_cast<Fixed&>(this->_y) = point.getY();
	}
	return (*this);
}

Point::~Point(void) { }

Fixed Point::getX(void) const {
	return (this->_x);
}

Fixed Point::getY(void) const {
	return (this->_y);
}
