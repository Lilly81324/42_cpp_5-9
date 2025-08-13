NAME = ex00

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = objs/

SRC = main.cpp ScalarConverter.cpp IntMath.cpp FloatMath.cpp
OBJ = $(addprefix $(OBJ_DIR), $(SRC:%.cpp=%.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "----<====>----\nSuccesfully compiled:\n\n$(NAME)"

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $@

run: $(NAME)
	./$(NAME)

val: $(NAME)
	valgrind --leak-check=full ./(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re