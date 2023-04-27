/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample4.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:44:54 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE4_CLASS_HPP
# define SAMPLE4_CLASS_HPP

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
