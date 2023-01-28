/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:56:14 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/28 10:53:32 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include <string>
# include <iostream>
# include <sstream>
# include <iomanip>

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# define DIAMOND "DiamondTrap "

class DiamondTrap: public ScavTrap, public FragTrap {
	public:
		DiamondTrap(void);
		DiamondTrap(std::string const& name);
		DiamondTrap(DiamondTrap const& diamond);
		~DiamondTrap(void);
		DiamondTrap& operator=(DiamondTrap const& diamond);

		std::string	getName(void) const;
		void		setName(std::string const& name);

		void		attack(const std::string& target);
		void		whoAmI(void);

	private:
		std::string	_name;
		static int	_diamondNb;
		void	_constructorMsg(std::string const& type);
};

#endif
