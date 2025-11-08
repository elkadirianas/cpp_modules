CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98
SRC=main.cpp  ZombieHorde.cpp  Zombie.cpp
INCS=Zombie.hpp
NAME=Zombie
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
