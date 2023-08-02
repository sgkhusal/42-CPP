# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 00:24:52 by sguilher          #+#    #+#              #
#    Updated: 2023/08/02 19:42:40 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		brain

CC =		c++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98 -g

SRC =		main.cpp
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
	@echo "             brain created"
	@echo "************************************"
	@echo "$(RESET)"

$(OBJ_DIR)/%.o:	%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
		$(RM_DIR) $(OBJ_DIR)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
