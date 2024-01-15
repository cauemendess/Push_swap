/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:00:01 by csilva-m          #+#    #+#             */
/*   Updated: 2024/01/10 14:00:01 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int value;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;

typedef struct s_push
{
	t_stack *stack_a;
	t_stack *stack_b;
	int argc;
	char **argv;
} t_push;

void	add_back(t_stack **stack, t_stack *new);
t_push	*init_all(int argc, char **argv);

void	push(t_stack **src, t_stack **dest);
void	do_pa(t_push *push_swap);
void	do_pb(t_push *push_swap);

void	swap(t_stack **stack);
void	do_sa(t_push *push_swap);
void	do_sb(t_push *push_swap);
void	do_ss(t_push *push_swap);

t_stack	*ft_stack_new(int content);
bool	is_ordened(t_stack *stack);
bool	have_duplicates(t_stack *stack);
void	ft_error(char *message);
void	free_stack(t_stack **stack);
void	ft_freestr(char **str);


#endif