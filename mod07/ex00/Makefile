NAME = ex00

CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = ./obj/

SRC = main.cpp
RAW_OBJS = $(SRC:%.cpp=%.o)
OBJS = $(addprefix $(OBJ_DIR), $(RAW_OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $< -o $@

$(OBJ_DIR)%.o: %.cpp $(OBJ_DIR)
	$(CXX) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

run: $(NAME)
	./$(NAME)

val: $(NAME)
	valgrind --leak-check=full ./$(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all run val clean fclean re
