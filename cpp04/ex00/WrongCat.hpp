/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:18:26 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/23 18:34:39 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
	public:
		WrongCat(void);
		~WrongCat(void);
		WrongCat(WrongCat const& wrongCat);
		WrongCat& operator=(WrongCat const& wrongCat);

		void	makeSound(void) const;
};

#endif