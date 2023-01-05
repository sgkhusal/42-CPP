/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 00:56:54 by sguilher          #+#    #+#             */
/*   Updated: 2023/01/05 13:51:04 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <string>
# include <iostream>

# define DEBUG		"\033[38;5;244m"
# define INFO		"\033[38;5;75m"
# define WARNING	"\033[1;33m"
# define ERROR		"\033[38;5;196m"
# define RESET		"\033[0m"

class	Harl {
	private:
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
		typedef void(Harl::* fptr)(void);
		typedef struct _s_line {
			std::string	level;
			fptr		f;
		} _t_line;
		static _t_line	_complainTable[4];
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

#endif
