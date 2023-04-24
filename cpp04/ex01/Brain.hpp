/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:01:26 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/23 20:35:51 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

# include <string>
# include <iostream>

# define LIGHT_PURPLE "\033[1;35m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

class Brain {
    public:
        Brain(void);
        Brain(Brain const& brain);
        ~Brain(void);
        Brain& operator=(Brain const& brain);

        std::string ideas[100];
    private:
        void	brainDescriptionPrint(std::string description);
};

#endif