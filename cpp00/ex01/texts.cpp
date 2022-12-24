/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texts.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:41:22 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/23 23:44:22 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "texts.hpp"

namespace Texts {
	void	welcome(void) {
		std::cout << std::endl << BLUE;
		std::cout << "                            ☎️ Welcome to ☎️" << std::endl << std::endl;
		std::cout << ORANGE;
		std::cout << "  __  __          _____  _                      _                 _    " << std::endl;
		std::cout << " |  \\/  |        |  __ \\| |                    | |               | |   " << std::endl;
		std::cout << " | \\  / |_   _   | |__) | |__   ___  _ __   ___| |__   ___   ___ | | __" << std::endl;
		std::cout << " | |\\/| | | | |  |  ___/| '_ \\ / _ \\| '_ \\ / _ \\ '_ \\ / _ \\ / _ \\| |/ /" << std::endl;
		std::cout << " | |  | | |_| |  | |    | | | | (_) | | | |  __/ |_) | (_) | (_) |   < " << std::endl;
		std::cout << " |_|  |_|\\__, |  |_|    |_| |_|\\___/|_| |_|\\___|_.__/ \\___/ \\___/|_|\\_\\" << std::endl;
		std::cout << "          __/ |                                                        " << std::endl;
		std::cout << "         |___/                                                         " << std::endl;
		std::cout << " ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️ ☎️" << std::endl;
		std::cout << RESET;
	}

	void	putActionsMenu(void) {
		std::cout << std::endl << BLUE;
		std::cout << "-------------------------------------------------------------------------" << std::endl;
		std::cout << "  _ __ ___   ___ _ __  _   _ " << std::endl;
		std::cout << " | '_ \\` _ \\/ _ \\ '_ \\| | | |" << std::endl;
		std::cout << " | | | | | |  __/ | | | |_| |" << std::endl;
		std::cout << " |_| |_| |_|\\___|_| |_|\\__,_|" << std::endl;
		std::cout << GREY << std::endl;
		std::cout << "* ADD: to save a new contact" << std::endl;
		std::cout << "* SEARCH: to display a specific contact" << std::endl;
		std::cout << "* EXIT: to quit My PhoneBook. (❗All data will be lost.)" << std::endl;
		std::cout << RESET << std::endl;
	}

	void	goodbye(void) {
		std::cout << std::endl << ORANGE;
		std::cout << "  ____                   _                            " << std::endl;
		std::cout << " |  _ \\                 | |                           " << std::endl;
		std::cout << " | |_) |_   _  ___      | |__  _   _  ___             " << std::endl;
		std::cout << " |  _ <| | | |/ _ \\     | '_ \\| | | |/ _ \\            " << std::endl;
		std::cout << " | |_) | |_| |  __/  _  | |_) | |_| |  __/  _   _   _ " << std::endl;
		std::cout << " |____/ \\__, |\\___| ( ) |_.__/ \\__, |\\___| (_) (_) (_)" << std::endl;
		std::cout << "         __/ |      |/          __/ |                 " << std::endl;
		std::cout << "        |___/                  |___/                  " << std::endl;
		std::cout << RESET << std::endl;
	}

	void	selectCommand(void) {
		std::cout << std::endl;
		instruction("Select a command:");
	}

	void	warning(const char* msg) {
		std::cout << RED << msg << RESET << std::endl;
	}

	void	success(const char* msg) {
		std::cout << std::endl << GREEN << msg << RESET << std::endl;
	}

	void	instruction(const char* msg) {
		std::cout << GREY << msg << RESET << std::endl;
	}
}
