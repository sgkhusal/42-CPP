/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample6.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:57:03 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE6_CLASS_HPP
# define SAMPLE6_CLASS_HPP

class	Sample6
{
	public:
		Sample6(int v);
		~Sample6(void);

		int	getFoo(void) const;
		int	compare(Sample6 *other) const;

	private:
		int	_foo;
};

#endif
