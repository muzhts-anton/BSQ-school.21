NAME = bsq

MAPGEN = mapgen
MAP = map

HDR_DIR = include

SRC = \
	src/main.c \
	src/base_funs.c \
	src/ft_atoi.c \
	src/input_file_processing.c \
	src/map_checker.c \
	src/show_result.c \
	src/sol_mem.c \
	src/solution.c \


OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean testmap mclean test

all: $(SRC)
	$(CC) -I $(HDR_DIR) -o $(NAME) -Wall -Wextra -Werror $(SRC)

testmap: $(MAPGEN)
	perl $(MAPGEN) 18 18 9 > $(MAP)
	cat $(MAP)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

mclean: fclean
	rm -rf $(MAP)

test: mclean all testmap
	./$(NAME) $(MAP)
