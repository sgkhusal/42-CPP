/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:44:31 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/28 09:30:57 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <string>
# include <iostream>
# include <sstream>

# define ORANGE	"\033[0;38;5;166m"
# define BLUE	"\033[38;5;75m"
# define CYAN "\033[0;36m"
# define GREEN	"\033[1;32m"
# define LIGHT_PURPLE "\033[1;35m"
# define YELLOW	"\033[1;33m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

# define CLAP_INIT_HP	10
# define CLAP_INIT_EP	10
# define CLAP_INIT_AD	0

# define CLAP "ClapTrap "

class ClapTrap {
	public:
		ClapTrap(void);
		ClapTrap(ClapTrap const& ct);
		ClapTrap(std::string const name);
		~ClapTrap(void);
		ClapTrap& operator=(ClapTrap const& ct);

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;
		void		setName(std::string const name);
		void		setHitPoints(int const hitPoints);
		void		setEnergyPoints(int const energyPoints);
		void		setAttackDamage(int const attackDamage);

	protected:
		std::string _name;
		int         _hitPoints;
		int         _energyPoints;
		int         _attackDamage;
		void		_constructorMsg(std::string type);
		void		attack_type(const std::string& target,
								const std::string& type);

	private:
		static int 	_robotNb;

};

#endif
