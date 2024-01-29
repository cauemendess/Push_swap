NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRC = $(addprefix src/, main.c push.c rotate.c swap.c \
clear_error.c validate.c reverse_rotate.c sort_3.c sort.c assign_index.c \
stack_utils.c initialize.c)
LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -I includes

all: $(LIBFT) $(NAME)
	@make -C libft --no-print-directory

clean:
	@make clean -C libft --no-print-directory
	rm -f $(OBJ)

re: fclean all

fclean: clean
	rm -f $(NAME)
