# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 11:42:13 by sguilher          #+#    #+#              #
#    Updated: 2023/08/02 19:42:40 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		tests

CC =		c++
CXXFLAGS =	-Wall -Wextra -Werror -g -std=c++98 #-D DEBUG=true

SRC =		main.cpp utils.cpp AMateria.cpp Cure.cpp Ice.cpp Character.cpp \
			MateriaSource.cpp
HEADERS =	utils.hpp AMateria.hpp Cure.hpp Ice.hpp ICharacter.hpp \
			Character.hpp IMateriaSource.hpp MateriaSource.hpp

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

re:			fclean all

.PHONY: all clean fclean re
