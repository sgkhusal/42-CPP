/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:24:04 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/23 17:22:50 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

# include <string>
# include <iostream>

# define CYAN "\033[0;36m"
# define LIGHT_PURPLE "\033[1;35m"

class ScavTrap: public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(ScavTrap const& st);
		ScavTrap(std::string const name);
		~ScavTrap(void);
		ScavTrap& operator=(ScavTrap const& st);

		void	guardGate(void);
		void	attack(const std::string& target);

	private:
		static int 	_sentinel_nb;

		void	_constructor_called(std::string type);
};

#endif