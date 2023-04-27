/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:06:16 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

# define RED	"\033[38;5;196m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

class	HumanB {
	public:
		HumanB(std::string name);
		~HumanB(void);
		void		attack(void);
		void		setWeapon(Weapon& weapon);
	private:
		std::string	_name;
		Weapon*		_weapon;
};

#endif
