# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 01:04:26 by sguilher          #+#    #+#              #
#    Updated: 2023/01/23 15:55:14 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		scavtrap

CC =		c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

SRC =		main.cpp ClapTrap.cpp ScavTrap.cpp
HEADERS =	ClapTrap.hpp ScavTrap.hpp
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
	$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "$(GREEN)"
	@echo "************************************"
	@echo "           scavtrap created"
	@echo "************************************"
	@echo "$(RESET)"

$(OBJ_DIR)/%.o:	%.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
		$(RM_DIR) $(OBJ_DIR)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
