/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:50:03 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

# define ORANGE	"\033[0;38;5;166m"
# define CYAN "\033[0;36m"
# define LIGHT_PURPLE "\033[1;35m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

class WrongAnimal{
	public:
		WrongAnimal(void);
		WrongAnimal(std::string const& type);
		WrongAnimal(WrongAnimal const& wrongAnimal);
		virtual ~WrongAnimal(void);
		WrongAnimal& operator=(WrongAnimal const& wrongAnimal);

		std::string	const&	getType(void) const;
		void				makeSound(void) const;

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
