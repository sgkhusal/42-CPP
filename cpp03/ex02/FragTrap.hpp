/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:13:29 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/27 00:13:07 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

# include <string>
# include <iostream>
# include <sstream>

# define FRAG_TRAP_INIT_HP	100
# define FRAG_TRAP_INIT_EP	100
# define FRAG_TRAP_INIT_AD	30

class FragTrap: public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(FragTrap const& st);
		FragTrap(std::string const name);
		~FragTrap(void);
		FragTrap& operator=(FragTrap const& st);

		void    highFiveGuys(void);

	private:
		static int 	_droid_nb;

		void	_constructor_msg(std::string type);
};

#endif
