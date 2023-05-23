/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:54:30 by sguilher          #+#    #+#             */
/*   Updated: 2023/05/22 23:03:30 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("Shrubbery Creation Form", SCF_SIGN, SCF_EXEC) {
	_description("canonical constructor", "ShrubberyCreationForm");
	this->_target = "undefined";
	this->_nbAction = 0;
}

ShrubberyCreationForm::ShrubberyCreationForm(
	std::string const& target
): AForm("Shrubbery Creation Form", SCF_SIGN, SCF_EXEC) {
	_description("grade constructor", "ShrubberyCreationForm");
	this->_target = target;
	this->_nbAction = 0;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	_description("destructor", "ShrubberyCreationForm");
}

ShrubberyCreationForm::ShrubberyCreationForm(
	ShrubberyCreationForm const& form):
		AForm("Shrubbery Creation Form", SCF_SIGN, SCF_EXEC) {
	_description("copy constructor", "ShrubberyCreationForm");
	*this = form;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
	ShrubberyCreationForm const& form) {
	_description("assign operator", "ShrubberyCreationForm");
	if (this != &form) {
		this->_target = form.getTarget();
		this->_nbAction = form.getNbAction();
	}
	return *this;
}

std::string	ShrubberyCreationForm::getTarget(void) const {
	return this->_target;
}

int	ShrubberyCreationForm::getNbAction(void) const {
	return this->_nbAction;
}

void	ShrubberyCreationForm::formAction(void) {
	std::ofstream	ofs;

	ofs.open((this->getTarget() + "_shrubbery").c_str());
	if (ofs.fail())
		throw CreateFileException();

	if (this->_nbAction % 2)
		ofs << "               ,@@@@@@@,\n"
			<< "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
			<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
			<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
			<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
			<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
			<< "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
			<< "       |o|        | |         | |\n"
			<< "       |.|        | |         | |\n"
			<< "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
	else
		ofs << "                                                         .\n"
			<< "                                              .         ;\n"
			<< "                 .              .              ;%     ;;\n"
			<< "                   ,           ,                :;%  %;\n"
			<< "                    :         ;                   :;%;'     .,\n"
			<< "           ,.        %;     %;            ;        %;'    ,;\n"
			<< "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
			<< "              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
			<< "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
			<< "                `%;.     ;%;     %;'         `;%%;.%;'\n"
			<< "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
			<< "                    `:%;.  :;bd%;          %;@%;'\n"
			<< "                      `@%:.  :;%.         ;@@%;'\n"
			<< "                        `@%.  `;@%.      ;@@%;\n"
			<< "                          `@%%. `@%%    ;@@%;\n"
			<< "                            ;@%. :@%%  %@@%;\n"
			<< "                              %@bd%%%bd%%:;\n"
			<< "                                #@%%%%%:;;\n"
			<< "                                %@@%%%::;\n"
			<< "                                %@@@%(o);  . '\n"
			<< "                                %@@@o%;:(.,'\n"
			<< "                            `.. %@@@o%::;\n"
			<< "                               `)@@@o%::;\n"
			<< "                                %@@(o)::;\n"
			<< "                               .%@@@@%::;\n"
			<< "                               ;%@@@@%::;.\n"
			<< "                              ;%@@@@%%:;;;.\n"
			<< "                          ...;%@@@@@%%:;;;;,..\n";

	if (ofs.bad())
		throw CreateFileException();
	ofs.close();
	this->_nbAction += 1;
}

const char* ShrubberyCreationForm::CreateFileException::what() const throw() {
	return "What a pity... Something went wrong while creating the shrubbery";
}
