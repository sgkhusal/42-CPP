/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:45:09 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/02 23:18:59 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>

class	Weapon {
	private:
		std::string	_type;
	public:
		Weapon(std::string type);
		~Weapon(void);
		std::string const &	getType(void) const;
		void				setType(std::string type);
};

#endif
