/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:32:07 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/23 22:14:45 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
    brainDescriptionPrint("constructor");
}

Brain::Brain(Brain const& brain) {
    brainDescriptionPrint("copy constructor");
    *this = brain;
}

Brain::~Brain(void) {
    brainDescriptionPrint("destructor");
}

Brain& Brain::operator=(Brain const& brain) {
    brainDescriptionPrint("operator=");
    if (this != &brain) {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = brain.ideas[i];
    }
    return (*this);
}

void	Brain::brainDescriptionPrint(std::string description) {
	std::cout << LIGHT_PURPLE << "Brain class " << description << " called"
			<< RESET << std::endl;
}