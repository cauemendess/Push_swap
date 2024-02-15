/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:38:08 by csilva-m          #+#    #+#             */
/*   Updated: 2024/02/15 17:38:09 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_min_node(t_stack *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

static int	cost_min(int min, int size, t_stack *temp)
{
	int	dist;

	dist = 0;
	while (temp)
	{
		if (temp->index == min)
			break ;
		dist++;
		temp = temp->next;
	}
	if (dist > (size + 1) / 2)
		dist = dist - size;
	return (dist);
}

void	small_sort(t_push *push, t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	len;

	len = get_stack_size(*stack_a);
	while (len != 3)
	{
		min = find_min_node(*stack_a);
		while ((*stack_a)->index != min)
		{
			if (cost_min(min, len, *stack_a) > 0)
				do_ra(push);
			else
				do_rra(push);
		}
		do_pb(push);
		len--;
	}
	sort_3(push);
	while (*stack_b)
		do_pa(push);
}
