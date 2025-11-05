NAME = PmergeMe
TARGET = 2 18 45 13 62 27 30 7 17 75 58 98 37 84 28 65 77 61 3 31 91 41 11 46 22 51 72 8 90 24

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
OBJ_DIR = ./obj/

SRC = PmergeMe.cpp main.cpp
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