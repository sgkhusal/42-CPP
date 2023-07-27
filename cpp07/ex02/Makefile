# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 13:27:01 by sguilher          #+#    #+#              #
#    Updated: 2023/07/27 01:07:50 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		array

CC =		c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98 -MMD -MP #-D DEBUG=true

SRC =		main.cpp
INCLUDE =	-I Array.hpp
OBJ_DIR =	./obj
OBJ =		$(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPS =		$(SRC:%.cpp=$(OBJ_DIR)/%.d)

# clean
RM =		-rm -f
RM_DIR =	rm -rf

# colors
GREEN	=	\033[1;32m
RESET	=	\033[0m

all:	$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) -o $@
	@echo "$(GREEN)"
	@echo "************************************"
	@echo "          array created"
	@echo "************************************"
	@echo "$(RESET)"

$(OBJ_DIR)/%.o:	%.cpp
	echo $<
	echo $@
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

print:
	@echo $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
		$(RM_DIR) $(OBJ_DIR)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re

-include $(DEPS)
