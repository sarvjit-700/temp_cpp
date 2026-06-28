# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/16 11:12:17 by ssukhija          #+#    #+#              #
#    Updated: 2026/06/16 11:12:17 by ssukhija         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

RESET = \033[;0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m

NAME = bureaucrat

#FLAGS
CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

#FILES
SRC = main.cpp Bureaucrat.cpp AForm.cpp\
		ShrubberyCreationForm.cpp\
		PresidentialPardonForm.cpp\
		RobotomyRequestForm.cpp\
		Intern.cpp
		
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)
	printf "Linking executable $(GREEN)[ok]$(RESET)\n"

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJ)
	printf "Cleaning object files $(YELLOW)[ok]$(RESET)\n"

fclean: clean
	$(RM) $(NAME)
	printf "Clean program $(YELLOW)[ok]$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re


