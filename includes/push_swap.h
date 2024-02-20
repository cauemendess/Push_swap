/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 18:03:42 by csilva-m          #+#    #+#             */
/*   Updated: 2024/02/15 18:03:42 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

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
	int		*argv_sort;
	t_bool	is_splited;
	long	size_a;
	long	size_b;
	int		bits;
}	t_push;

t_push	*init_all(int argc, char **argv);
void	init_stack(t_push *push_swap);
void	add_back(t_stack **stack, t_stack *stack_new);
t_stack	*get_stack_last(t_stack *stack);
t_stack	*ft_stack_new(int content);
int		get_stack_size(t_stack *stack);

void	push(t_stack **src, t_stack **dest);
void	do_pa(t_push *push_swap);
void	do_pb(t_push *push_swap);

void	swap(t_stack **stack);
void	do_sa(t_push *push_swap);
void	do_sb(t_push *push_swap);
void	do_ss(t_push *push_swap);

void	rotate(t_stack **stack);
void	do_ra(t_push *push_swap);
void	do_rb(t_push *push_swap);
void	do_rr(t_push *push_swap);

void	reverse_rotate(t_stack **stack);
void	do_rra(t_push *push_swap);
void	do_rrb(t_push *push_swap);
void	do_rrr(t_push *push_swap);

void	sort_3(t_push *push_swap);
void	radix(t_push *push, t_stack **stack_a, t_stack **stack_b, int bits);

int		get_stack_size(t_stack *stack);
t_stack	*ft_stack_new(int content);
t_bool	is_ordened(t_stack *stack);
t_bool	have_duplicates(t_stack *stack);
void	free_stack(t_stack **stack);
void	ft_freestr(char **str);
void	ft_error(char *message);
void	ft_clear_err(char *message, t_push *push_swap);
void	ft_finish(t_push *push_swap);

void	print_stack(t_stack *stack_a);
int		*tab_argv(t_push *push);
void	assign_index(t_push *push);
void	validate(t_push *push);
t_stack	*find_max_node(t_stack *stack);
void	small_sort(t_push *push, t_stack **stack_a, t_stack **stack_b);
int		count_bits(int max);

#endif