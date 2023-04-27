/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample5.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:19:46 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE5_CLASS_HPP
# define SAMPLE5_CLASS_HPP

class	Sample5
{
	public:
		Sample5(void);
		~Sample5(void);

		int		getFoo(void) const;
		void	setFoo(int v);

	private:
		int		_foo;
};

#endif
