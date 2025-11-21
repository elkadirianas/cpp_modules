
CC=c++
CFLAGS=-Wall -Wextra -Werror
SRC=HumanA.cpp  HumanB.cpp Weapon.cpp main.cpp  
NAME=War
ICNS=Weapon.hpp HumanA.hpp  HumanB.hpp  
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

