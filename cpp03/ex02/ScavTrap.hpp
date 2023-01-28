/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:24:04 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/28 09:30:43 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

# include <string>
# include <iostream>
# include <sstream>

# define SCAV_INIT_HP	100
# define SCAV_INIT_EP	50
# define SCAV_INIT_AD	20

# define SCAV "ScavTrap "

class ScavTrap: public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(ScavTrap const& st);
		ScavTrap(std::string const name);
		~ScavTrap(void);
		ScavTrap& operator=(ScavTrap const& st);

		void	guardGate(void);
		void	attack(const std::string& target);

	protected:
		void	_constructorMsg(std::string type);

	private:
		static int 	_sentinelNb;
};

#endif
