# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 18:48:26 by sguilher          #+#    #+#              #
#    Updated: 2023/08/06 17:14:44 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		mutant_stack

CC =		c++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98 -MMD -MP #-D DEBUG=true

SRC =		main.cpp tests_utils.cpp
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
	@echo "          mutant_stack created"
	@echo "************************************"
	@echo "$(RESET)"

$(OBJ_DIR)/%.o:	%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ $(INCLUDE)

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
