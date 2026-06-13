# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/01 10:46:02 by puzzlesanal       #+#    #+#              #
#    Updated: 2025/12/01 10:46:05 by puzzlesanal      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------- Binary ----------
NAME    := ex02

# ---------- Compiler ----------
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98

# ---------- Source Files ----------
SRC := \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	main.cpp

# ---------- Header Files ----------
INC := \
	Bureaucrat.hpp \
	AForm.hpp \
	ShrubberyCreationForm.hpp \
	RobotomyRequestForm.hpp \
	PresidentialPardonForm.hpp \
	color.hpp

# ---------- Objects ----------
OBJ := $(SRC:.cpp=.o)

# ---------- Farben ----------
GRN := \033[92m
BLU := \033[94m
RED := \033[91m
RST := \033[0m

# ---------- Build Rules ----------
all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "$(GRN)[OK]$(RST) linked $(NAME)"

%.o: %.cpp $(INC)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(BLU)[CC]$(RST) $<"

# ---------- Clean ----------
clean:
	@rm -f $(OBJ)
	@echo "$(RED)cleaned objects$(RST)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)removed binary $(NAME)$(RST)"

re: fclean all

.PHONY: all clean fclean re