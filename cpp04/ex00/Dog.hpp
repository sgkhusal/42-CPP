/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:20:42 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/20 11:48:05 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"

class Dog: public Animal{
	public:
		Dog(void);
		~Dog(void);
		Dog(Dog const& dog);
		Dog& operator=(Dog const& dog);
		
		void	makeSound(void);
};

#endif