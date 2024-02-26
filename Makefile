CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O3

NAME = push_swap
NAME_BONUS = checker

BIN = ./bin/
INC_DIR = ./includes/

SRC = $(addprefix src/, main.c push.c rotate.c swap.c \
clear_error.c validate.c reverse_rotate.c sort_3.c sort.c assign_index.c \
stack_utils.c initialize.c small_sort.c target_pos.c set_cost.c moves.c)

OBJ = $(addprefix $(BIN), $(notdir $(SRC:.c=.o)))

SRC_BONUS = $(addprefix bonus/, checker_bonus.c clear_err_bonus.c init_bonus.c \
push_bonus.c reverse_rotate_bonus.c rotate_bonus.c stack_utils_bonus.c swap_bonus.c \
validate_bonus.c)

OBJ_BONUS = $(addprefix $(BIN), $(notdir $(SRC_BONUS:.c=.o)))

LIBFT = libft/libft.a

all: $(BIN) $(OBJ) $(LIBFT) $(NAME)

bonus: $(BIN) $(OBJ_BONUS) $(LIBFT) $(NAME_BONUS)

$(LIBFT):
	@make -C ./libft --no-print-directory

$(BIN):
	@mkdir -p $(BIN)

$(BIN)%.o: src/%.c $(INC_DIR)push_swap.h | $(BIN)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)


$(BIN)%.o: bonus/%.c $(INC_DIR)checker_bonus.h | $(BIN)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

clean:
	@make clean -C ./libft --no-print-directory
	rm -rf $(BIN)

re: fclean all

fclean: clean
	rm -f $(NAME)
	rm -rf $(NAME_BONUS)
	@make fclean -C libft --no-print-directory

.PHONY: all clean fclean re libft

