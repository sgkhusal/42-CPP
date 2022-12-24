/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texts.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:52:10 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/23 23:43:37 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTS_H
# define TEXTS_H

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
