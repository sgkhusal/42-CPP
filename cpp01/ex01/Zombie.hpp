/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:25:00 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/02 21:04:00 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

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
		void		announce(void);
		void		setZombieName(std::string name);
};

Zombie*	zombieHorde(int n, std::string name);

#endif
