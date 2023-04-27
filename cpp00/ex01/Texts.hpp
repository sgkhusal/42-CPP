/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Texts.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:52:10 by sguilher          #+#    #+#             */
/*   Updated: 2023/04/27 12:59:29 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTS_HPP
# define TEXTS_HPP

# include <iostream>

# define ORANGE	"\033[0;38;5;166m"
# define BLUE	"\033[38;5;75m"
# define GREEN	"\033[1;32m"
# define RED	"\033[38;5;196m"
# define GREY	"\033[38;5;244m"
# define RESET	"\033[0m"

namespace Texts {
	void	welcome(void);
	void	putActionsMenu(void);
	void	selectCommand(void);
	void	goodbye(void);
	void	warning(const char* msg);
	void	success(const char* msg);
	void	instruction(const char* msg);
}

#endif
