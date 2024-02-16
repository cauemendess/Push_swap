/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:55:33 by csilva-m          #+#    #+#             */
/*   Updated: 2024/02/16 18:26:23 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	if (second->next != NULL)
		second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	*stack = second;
}

void	do_sa(t_push *push_swap)
{
	swap(&push_swap->stack_a);
	ft_printf("sa\n");
}

void	do_sb(t_push *push_swap)
{
	swap(&push_swap->stack_b);
	ft_printf("sb\n");
}

void	do_ss(t_push *push_swap)
{
	swap(&push_swap->stack_a);
	swap(&push_swap->stack_b);
	ft_printf("ss\n");
}
