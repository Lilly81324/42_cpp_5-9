NAME = ex01

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ_DIR = ./obj/
SRC = main.cpp Span.cpp
RAW_OBJ = $(SRC:%.cpp=%.o)
OBJ = $(addprefix $(OBJ_DIR), $(RAW_OBJ))

all : $(NAME)

show:
	@echo "-- SRC --"
	@echo $(SRC)
	@echo "-- RAW --"
	@echo $(RAW_OBJ)
	@echo "-- OBJ --"
	@echo $(OBJ)

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
