#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H


# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>


typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_stack	t_stack;
struct s_stack
{
	int		value;
	int		index;
	t_stack	*next;
	t_stack	*prev;
};


typedef struct s_push
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		argc;
	char	**argv;
	t_bool	is_splited;
	long	size_a;
	long	size_b;
}	t_push;


t_push	*init_all(int argc, char **argv);
void	init_stack(t_push *push_swap);
void	add_back(t_stack **stack, t_stack *stack_new);
t_stack	*get_stack_last(t_stack *stack);
t_stack	*ft_stack_new(int content);
int		get_stack_size(t_stack *stack);
void	ft_finish(t_push *push_swap);
void	ft_clear_err(char *str, t_push *push_swap);
void	ft_error(char *message);
void	free_stack(t_stack **stack);
t_bool	is_ordened(t_stack *stack);
void	validate(t_push *push);
void	ft_freestr(char **str);



void	do_sa(t_push *push_swap);
void	do_sb(t_push *push_swap);
void	do_ss(t_push *push_swap);

void	do_ra(t_push *push_swap);
void	do_rb(t_push *push_swap);
void	do_rr(t_push *push_swap);

void	do_pa(t_push *push_swap);
void	do_pb(t_push *push_swap);

void	do_rra(t_push *push_swap);
void	do_rrb(t_push *push_swap);
void	do_rrr(t_push *push_swap);

#endif