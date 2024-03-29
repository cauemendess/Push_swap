/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:54:29 by csilva-m          #+#    #+#             */
/*   Updated: 2024/02/15 17:54:29 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*new_last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	new_last = *stack;
	while (new_last->next != NULL)
		new_last = new_last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	new_last->next = first;
	first->prev = new_last;
	first->next = NULL;
}

void	do_ra(t_push *push_swap)
{
	rotate(&push_swap->stack_a);
	ft_printf("ra\n");
}

void	do_rb(t_push *push_swap)
{
	rotate(&push_swap->stack_b);
	ft_printf("rb\n");
}

void	do_rr(t_push *push_swap)
{
	rotate(&push_swap->stack_a);
	rotate(&push_swap->stack_b);
	ft_printf("rr\n");
}
