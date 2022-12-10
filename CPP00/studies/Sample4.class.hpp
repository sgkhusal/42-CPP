/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample4.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:44:54 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/10 16:23:55 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE4_CLASS_H
# define SAMPLE4_CLASS_H

class	Sample4
{
	public:
		Sample4(void);
		~Sample4(void);
		int		publicFoo;
		void	publicBar(void) const;
	private:
		int		_privateFoo;
		void	_privateBar(void) const;
};

#endif
