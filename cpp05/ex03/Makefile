# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 17:20:08 by sguilher          #+#    #+#              #
#    Updated: 2023/08/02 19:42:40 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		tests

CC =		c++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98 #-D DEBUG=true

SRC =		main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
HEADERS =	Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp \
			RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp
INCLUDE =	-I ./
OBJ_DIR =	./obj
OBJ =		$(SRC:%.cpp=$(OBJ_DIR)/%.o)

# clean
RM =		-rm -f
RM_DIR =	rm -rf

# colors
GREEN	=	\033[1;32m
RESET	=	\033[0m

all:	$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $@
	@echo "$(GREEN)"
	@echo "************************************"
	@echo "          tests created"
	@echo "************************************"
	@echo "$(RESET)"

$(OBJ_DIR)/%.o:	%.cpp $(HEADERS)
	$(CC) $(CXXFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
		$(RM_DIR) $(OBJ_DIR)

fclean:		clean
		$(RM) $(NAME)
		rm *_shrubbery

re:			fclean all

.PHONY: all clean fclean re
