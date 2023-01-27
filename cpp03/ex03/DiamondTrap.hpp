/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:56:14 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/26 22:04:01 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include <string>
# include <iostream>

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const& diamond);
		~DiamondTrap(void);
		DiamondTrap& operator=(DiamondTrap const& diamond);

		//void	attack(const std::string& target);

	private:
		std::string _name;
		static int 	_diamond_nb;

	protected:
		void	_constructor_msg(std::string type);
};

#endif
