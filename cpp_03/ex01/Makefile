SRC = ClapTrap.cpp main.cpp  ScavTrap.cpp

OBJ = $(SRC:.cpp=.o)

FALGS = -Wall -Werror -Wextra -std=c++98

NAME = ScavTrap

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FALGS) $(OBJ) -o $(NAME) 

%.o : %.cpp ClapTrap.hpp ScavTrap.hpp
	c++ $(FALGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all