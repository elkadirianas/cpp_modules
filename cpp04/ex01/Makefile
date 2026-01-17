SRC = Animal.cpp  Cat.cpp main.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

OBJ = $(SRC:.cpp=.o)

FALGS = -Wall -Werror -Wextra -std=c++98

NAME = Animal

all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FALGS) $(OBJ) -o $(NAME) 

%.o : %.cpp Animal.hpp Cat.cpp Dog.hpp WrongAnimal.hpp WrongCat.hpp
	c++ $(FALGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all