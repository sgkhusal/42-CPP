/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample6.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:57:03 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/10 19:06:46 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE6_CLASS_H
# define SAMPLE6_CLASS_H

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
