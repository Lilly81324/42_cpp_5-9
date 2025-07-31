NAME = ex05

OBJ_DIR = ./obj/

RAW_SRC = \
main \
Bureaucrat

SRC = $(addsuffix .cpp, $(RAW_SRC))
RAW_OBJ = $(SRC:%.cpp=%.o)
OBJS = $(addprefix $(OBJ_DIR), $(RAW_OBJ))

CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $@
	@echo "----<====>----\nSuccesfully compiled:" $@

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
.SILENT: all run val clean fclean re