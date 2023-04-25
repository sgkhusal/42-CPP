/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:18:26 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/20 11:47:55 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"

class Cat: public Animal{
	public:
		Cat(void);
		~Cat(void);
		Cat(Cat const& cat);
		Cat& operator=(Cat const& cat);

		void	makeSound(void) const;
};

#endif
