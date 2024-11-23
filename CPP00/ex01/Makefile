NAME=phonebook
CC=c++
S=-fsanitize=address -g
FLAGS=-Wall -Wextra -Werror $(s)
SRC= phonebook.cpp
OBJ= $(SRC:.cpp=.o)
ADDFLAGS= -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

