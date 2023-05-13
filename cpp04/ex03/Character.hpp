/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 22:22:45 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/12 23:18:10 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include "ICharacter.hpp"

# define SLOTS 4

class Character: public ICharacter {
    public:
        Character(void);
        Character(std::string const& name);
        Character(Character const& character);
		~Character(void);
		Character& operator=(Character const& character);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

    private:
        std::string         _name;
        AMateria*           inventory[SLOTS];
        static std::string  _charactersSample[30];
};

#endif
