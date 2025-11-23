# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 18:50:15 by puzzlesanal       #+#    #+#              #
#    Updated: 2025/11/23 17:13:47 by puzzlesanal      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ex00/Makefile

# ---------- Minimal, nicht relinkend, mit Farbe ----------
NAME    := ex01
CXX     := c++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98

SRC := \
	Bureaucrat.cpp \
	Form.cpp \
	main.cpp

INC := \
	Bureaucrat.hpp \
	Form.hpp \
	colors.hpp

OBJ := $(SRC:.cpp=.o)

# Farben
GRN := \033[92m
BLU := \033[94m
RST := \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "$(GRN)[OK]$(RST) linked $(NAME)"

%.o: %.cpp $(INC)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(BLU)[CC]$(RST) $<"

clean:
	@rm -f $(OBJ)
	@echo "cleaned objects"

fclean: clean
	@rm -f $(NAME)
	@echo "removed binary"

re: fclean all

.PHONY: all clean fclean re
