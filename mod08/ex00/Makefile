NAME = ex00

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I.

OBJ_DIR = ./obj/
SRC = main.cpp
RAW_OBJ = $(SRC:%.cpp=%.o)
OBJ = $(addprefix $(OBJ_DIR), $(RAW_OBJ))

all : $(NAME)

show:
	echo $(SRC)
	echo
	echo $(RAW_OBJ)
	echo
	echo $(OBJ)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(OBJ_DIR)%.o : %.cpp $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

run: $(NAME)
	./$(NAME)

val: $(NAME)
	valgrind --leak-check=full --track-fds=yes --trace-children=yes ./$(NAME)

re: fclean all

.PHONY: all clean fclean run val re
