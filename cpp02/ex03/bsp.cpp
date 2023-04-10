/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:13:47 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/24 18:09:01 by sguilher         ###   ########.fr       */
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

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	area;
	Fixed	sum_areas;
	Fixed	a1, a2, a3;
	Fixed	zero;

	area = triangle_area(a, b, c);
	a1 = triangle_area(a, b, point);
	a2 = triangle_area(a, point, c);
	a3 = triangle_area(point, b, c);
	if (a1 == zero || a2 == zero || a3 == zero)
		return (false);
	sum_areas = a1 + a2 + a3;
	return (area == sum_areas);
}
