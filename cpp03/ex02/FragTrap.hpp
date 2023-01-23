/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:13:29 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/23 19:35:25 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

# include <string>
# include <iostream>

# define CYAN "\033[0;36m"

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

		void	_constructor_called(std::string type);
};

#endif