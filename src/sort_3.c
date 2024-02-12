/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:42:03 by csilva-m          #+#    #+#             */
/*   Updated: 2024/02/12 14:51:00 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
	
t_stack *find_max_node(t_stack *stack)
{
    t_stack *cur;
	cur = stack;
    t_stack *max_node;
	max_node = cur;
    while (cur != NULL)
    {
        if (cur->index > max_node->index)
            max_node = cur;
        cur = cur->next;
    }

    return max_node;
}

void	sort_3(t_push *push_swap)
{
	t_stack *high;
	high = find_max_node(push_swap->stack_a);
	if(is_ordened(push_swap->stack_a))
		return;
	if(push_swap->stack_a->index == high->index)
		do_ra(push_swap);
	else if(push_swap->stack_a->next->index == high->index)
		do_rra(push_swap);
	if(push_swap->stack_a->index > push_swap->stack_a->next->index)
		do_sa(push_swap);
}
