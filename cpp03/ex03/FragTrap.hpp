/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:13:29 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# include <string>
# include <iostream>
# include <sstream>

# define FRAG_INIT_HPPP	100
# define FRAG_INIT_EP	100
# define FRAG_INIT_AD	30

# define FRAG "FragTrap "

class FragTrap: virtual public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(FragTrap const& ft);
		FragTrap(std::string const& name);
		~FragTrap(void);
		FragTrap& operator=(FragTrap const& ft);

		void	highFiveGuys(void);

	private:
		static int	_droidNb;
		void		_constructorMsg(std::string const& type);
};

#endif
