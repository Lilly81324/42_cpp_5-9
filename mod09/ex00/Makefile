NAME = btc
TARGET = test.txt

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ_DIR = ./obj/

SRC = main.cpp
RAW = $(SRC:%.cpp=%.o)
OBJ = $(addprefix $(OBJ_DIR), $(RAW))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

show:
	@echo "--- SRC ---"
	@echo "$(SRC)"
	@echo "--- RAW ---"
	@echo "$(RAW)"
	@echo "--- OBJ ---"
	@echo "$(OBJ)"

run: $(NAME)
	./$(NAME) $(TARGET)

val: $(NAME)
	valgrind --leak-check=full --track-fds=yes --trace-children=yes ./$(NAME) $(TARGET)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all show run val clean fclean re