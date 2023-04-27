/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:25:00 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

# define ORANGE	"\033[0;38;5;166m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

class Zombie {
	private:
		std::string	_name;
	public:
		Zombie(void);
		~Zombie(void);
		static int	totalZombies;
		void		announce(void) const;
		void		setZombieName(std::string const name);
};

Zombie*	zombieHorde(int n, std::string const name);

#endif
