/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:20:42 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/23 20:31:44 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal{
	public:
		Dog(void);
		~Dog(void);
		Dog(Dog const& dog);
		Dog& operator=(Dog const& dog);

		void	makeSound(void) const;
	private:
		Brain* brain; // = NULL;
};

#endif