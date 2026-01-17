SRC = ClapTrap.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

FALGS = -Wall -Werror -Wextra -std=c++98

NAME = ClapTrap

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FALGS) $(OBJ) -o $(NAME) 

%.o : %.cpp ClapTrap.hpp
	c++ $(FALGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all