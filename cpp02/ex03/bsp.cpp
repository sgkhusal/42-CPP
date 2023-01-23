/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:13:47 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/22 22:41:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed triangle_area(Point const a, Point const b, Point const c) {
	Fixed area;
	area = a.getX() * (b.getY() - c.getY())
			+ b.getX() * (c.getY() - a.getY())
			+ c.getX() * (a.getY() - b.getY());
	if (area < 0)
		area = area * Fixed(-1);
	area = area / Fixed(2);
	return (area);
}

static bool compare_fixed(Fixed const a, Fixed const b)
{
	if (a > b)
		return ((a - b) < EPSILON);
	return ((b - a) < EPSILON);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	area;
	Fixed	sum_areas;

	area = triangle_area(a, b, c);
	sum_areas = triangle_area(a, b, point)
				+ triangle_area(a, point, c)
				+ triangle_area(point, b, c);
	return (compare_fixed(area, sum_areas));
}
