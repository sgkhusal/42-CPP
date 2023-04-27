/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:13:49 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

# define EPSILON 0.00001f

class Point {
	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const& point);
		Point& operator=(Point const& point);
		~Point(void);

		Fixed getX(void) const;
		Fixed getY(void) const;

	private:
		Fixed const	_x, _y;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
