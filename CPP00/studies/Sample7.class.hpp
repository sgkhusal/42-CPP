/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample7.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:04:17 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/10 22:06:25 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE7_CLASS_H
# define SAMPLE7_CLASS_H

class	Sample7
{
	public:
		Sample7(void);
		~Sample7(void);
		static int	getNbInst(void);

	private:
		static int	_nbInst;
};

#endif
