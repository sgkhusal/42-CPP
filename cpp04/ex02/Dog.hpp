/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:20:42 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/23 23:47:25 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal{
	public:
		Dog(void);
		~Dog(void);
		Dog(Dog const& dog);
		Dog& operator=(Dog const& dog);

		void	makeSound(void) const;
		Brain*	getBrain(void) const;
	private:
		Brain* _brain;
};

#endif