#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int value;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;



void	add_back(t_stack **stack, t_stack *new);
void	init_all(int argc, char **argv);
void	push(t_stack **src, t_stack **dest);
t_stack	*ft_stack_new(int content);

#endif