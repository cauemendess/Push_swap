/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:46:40 by csilva-m          #+#    #+#             */
/*   Updated: 2024/02/26 15:46:41 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*cur;

	if (!*stack || !(*stack)->next)
		return ;
	cur = *stack;
	while (cur->next != NULL)
		cur = cur->next;
	cur->prev->next = NULL;
	cur->prev = NULL;
	cur->next = *stack;
	(*stack)->prev = cur;
	*stack = cur;
}

void	do_rra(t_push *push_swap)
{
	reverse_rotate(&push_swap->stack_a);
}

void	do_rrb(t_push *push_swap)
{
	reverse_rotate(&push_swap->stack_b);
}

void	do_rrr(t_push *push_swap)
{
	reverse_rotate(&push_swap->stack_a);
	reverse_rotate(&push_swap->stack_b);
}
