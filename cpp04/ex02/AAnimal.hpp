/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:11:25 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/24 23:21:14 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

# include <string>
# include <iostream>

# define ORANGE	"\033[0;38;5;166m"
# define BLUE	"\033[38;5;75m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

class AAnimal{
	public:
		AAnimal(void);
		AAnimal(std::string const& type);
		AAnimal(AAnimal const& animal);
		virtual ~AAnimal(void);
		AAnimal& operator=(AAnimal const& animal);

		std::string	const&	getType(void) const;
		virtual void		makeSound(void) const = 0;

	protected:
		std::string type;
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