# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 09:39:07 by sguilher          #+#    #+#              #
#    Updated: 2023/08/15 11:26:34 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		RPN

CC =		c++
CXXFLAGS =	-Wall -Wextra -Werror -std=c++98 -MMD -MP #-D DEBUG=true

SRC =		main.cpp RPN.cpp
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
	@echo "          RPN created"
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
