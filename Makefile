NAME = push_swap
NAME_BONUS = checker

CFLAGS = -Wall -Wextra -Werror -g -O3
SRC_DIR = src
SRC = $(addprefix src/, main.c push.c rotate.c swap.c \
clear_error.c validate.c reverse_rotate.c sort_3.c sort.c assign_index.c \
stack_utils.c initialize.c small_sort.c)
LIBFT = libft/libft.a

INC_DIR = -I./includes -I./$(SRC_DIR)
OBJ = $(SRC:.c=.o)

all: $(OBJ) $(LIBFT) $(NAME)

bonus: $(OBJ_BONUS) $(LIBFT) $(NAME_BONUS)

$(LIBFT):
	@make -C ./libft --no-print-directory

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

clean:
	@make clean -C ./libft --no-print-directory
	rm -f $(OBJ)

re: fclean all

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft --no-print-directory

.PHONY: all clean fclean re libft
