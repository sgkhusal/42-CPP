# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 11:42:13 by sguilher          #+#    #+#              #
#    Updated: 2023/04/27 11:56:38 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		tests

CC =		c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98

SRC =		main.cpp tests.cpp
HEADERS =	tests.hpp
#SRC =		main.cpp tests.cpp AAMateria.cpp Cure.cpp Ice.cpp
#HEADERS =	tests.hpp AAMateria.hpp Cure.hpp Ice.hpp ICharacter.hpp

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
	@echo "          tests created"
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
