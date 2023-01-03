/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:53:57 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/02 23:50:43 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include <iostream>
# include "Weapon.hpp"

# define RED	"\033[38;5;196m"
# define RESET	"\033[0m"

class	HumanA {
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);
		void		attack(void);
	private:
		std::string	_name;
		Weapon&		_weapon;
};

#endif
