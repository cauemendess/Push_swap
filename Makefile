NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRC = src/*.c
LIBFT = libft/libft.a 

$(NAME): all
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME) -I includes

all:
	@make -C libft --no-print-directory

clean:
	@make clean -C libft --no-print-directory

re: fclean all

fclean: clean
	rm -f $(NAME)
