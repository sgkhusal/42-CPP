/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample3.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:57:41 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/07 22:02:20 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE3_CLASS_HPP
# define SAMPLE3_CLASS_HPP

class	Sample3
{
	public:
		Sample3(float const f);
		~Sample3(void);
		float const	pi;
		int			qd;
		void	bar(void) const;
};

#endif
