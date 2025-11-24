CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98
SRC=main.cpp Harl.cpp
NAME=Harl
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp Harl.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all