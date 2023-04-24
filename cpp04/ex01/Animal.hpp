/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:11:25 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/23 18:29:18 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>
# include <iostream>

# define ORANGE	"\033[0;38;5;166m"
# define BLUE	"\033[38;5;75m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

class Animal{
	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const& animal);
		virtual ~Animal(void);
		Animal& operator=(Animal const& animal);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;

	protected:
		std::string _type;
		void	specificDescriptionPrint(
					std::string class_name,
					std::string description,
					std::string color
		);
	private:
		void	genericDescriptionPrint(
					std::string description,
					std::string color
		);
};

#endif