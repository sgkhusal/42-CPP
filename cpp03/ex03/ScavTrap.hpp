/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:24:04 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/26 18:50:54 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

# include <string>
# include <iostream>

# define CYAN "\033[0;36m"

class ScavTrap: virtual public ClapTrap {
	public:
		ScavTrap(void);
		ScavTrap(ScavTrap const& st);
		ScavTrap(std::string const name);
		~ScavTrap(void);
		ScavTrap& operator=(ScavTrap const& st);

		void	guardGate(void);
		void	attack(const std::string& target);

	protected:
		void	_constructor_msg(std::string type);

	private:
		static int 	_sentinel_nb;
};

#endif
