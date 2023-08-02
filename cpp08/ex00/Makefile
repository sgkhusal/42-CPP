# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 11:09:58 by sguilher          #+#    #+#              #
#    Updated: 2023/08/02 18:20:01 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		easyfind

CC =		c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98 -MMD -MP

SRC =		main.cpp
INCLUDE =	-I ./
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
	@echo "          easyfind created"
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
