/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:18:18 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/07 23:10:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sample3.class.hpp"

int	main(void)
{
	Sample3	instance(3.14);
	instance.bar();
	instance.qd = 24;
	instance.bar();
	return (0);
}
