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
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_b, t_stack **stack_a);


void	swap(t_stack **stack);
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);

t_stack	*ft_stack_new(int content);

#endif