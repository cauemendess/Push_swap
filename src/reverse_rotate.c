/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:15:37 by csilva-m          #+#    #+#             */
/*   Updated: 2024/01/15 17:37:07 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void reverse_rotate(t_stack **stack)
{
    if (!*stack || !(*stack)->next)
        return;
    t_stack *cur;
	cur = *stack;
    while (cur->next != NULL)
        cur = cur->next;
    cur->prev->next = NULL;
    cur->prev = NULL;
    cur->next = *stack;
    (*stack)->prev = cur;
    *stack = cur;
}

void do_rra(t_push *push_swap)
{
	reverse_rotate(&push_swap->stack_a);
	ft_printf("rra\n");
}
void do_rrb(t_push *push_swap)
{
	reverse_rotate(&push_swap->stack_b);
	ft_printf("rrb\n");
}

void do_rrr(t_push *push_swap)
{
	reverse_rotate(&push_swap->stack_a);
	reverse_rotate(&push_swap->stack_b);
	ft_printf("rrr\n");
}
