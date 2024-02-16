NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -g -O3
SRC_DIR = src
SRC = $(addprefix src/, main.c push.c rotate.c swap.c \
clear_error.c validate.c reverse_rotate.c sort_3.c sort.c assign_index.c \
stack_utils.c initialize.c small_sort.c)
LIBFT = libft/libft.a

INC_DIR = -I./includes -I./$(SRC_DIR)
OBJ = $(SRC:.c=.o)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

all: $(LIBFT) $(NAME)
	@make -C libft --no-print-directory

clean:
	@make clean -C libft --no-print-directory
	rm -f $(OBJ)

re: fclean all

fclean: clean
	rm -f $(NAME)
