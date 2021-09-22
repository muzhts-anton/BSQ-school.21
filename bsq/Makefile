NAME = bsq

PROGFILES = tmap.txt

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

.PHONY: all clean fclean testmap mclean test vlgdtest

all: $(SRC)
	$(CC) -I $(HDR_DIR) -o $(NAME) -Wall -Wextra -Werror $(SRC)

vlgdtest: all
	valgrind --leak-check=full \
             --show-leak-kinds=all \
             --track-origins=yes \
             ./$(NAME)

testmap: $(MAPGEN)
	perl $(MAPGEN) 18 18 9 > $(MAP)
	cat $(MAP)

clean:
	rm -rf $(OBJ)
	rm -rf $(PROGFILES)

fclean: clean
	rm -rf $(NAME)

mclean: fclean
	rm -rf $(MAP)

test: mclean all testmap
	./$(NAME) $(MAP)
	make mclean
