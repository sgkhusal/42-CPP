/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:18:26 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/23 20:31:37 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal{
	public:
		Cat(void);
		~Cat(void);
		Cat(Cat const& cat);
		Cat& operator=(Cat const& cat);

		void	makeSound(void) const;
	private:
		Brain* brain; // = NULL;
};

#endif