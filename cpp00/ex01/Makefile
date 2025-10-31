SRC = Contact.cpp PhoneBook.cpp main.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = PhoneBook
OBJ = $(SRC:.cpp=.o)
INCS = Contact.hpp PhoneBook.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
