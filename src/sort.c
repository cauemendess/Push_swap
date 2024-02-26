/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:38:17 by csilva-m          #+#    #+#             */
/*   Updated: 2024/02/26 15:41:32 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_b(t_push *push, t_stack **stack_a)
{
	int	i;
	int	stack_size;

	i = 0;
	stack_size = get_stack_size(*stack_a) / 2;
	while (get_stack_size(*stack_a) > stack_size)
	{
		if ((*stack_a)->index < stack_size)
			do_pb(push);
		else
			do_ra(push);
		i++;
	}
	while (get_stack_size(*stack_a) > 3)
		do_pb(push);
	sort_3(push);
}

int	get_min_pos(t_stack **stack)
{
	t_stack	*temp;
	int		min_index;
	int		min_pos;

	min_index = INT_MAX;
	get_positon(stack);
	temp = *stack;
	while (temp)
	{
		if (temp->index < min_index)
		{
			min_index = temp->index;
			min_pos = temp->pos;
		}
		temp = temp->next;
	}
	return (min_pos);
}

void	shift(t_push *push, t_stack **stack_a)
{
	int	size_stack;
	int	min;

	min = get_min_pos(stack_a);
	size_stack = get_stack_size(*stack_a);
	if (min > size_stack / 2)
	{
		while (min < size_stack)
		{
			do_rra(push);
			min++;
		}
	}
	else
	{
		while (min > 0)
		{
			do_ra(push);
			min--;
		}
	}
}

void	sort(t_push *push, t_stack **stack_a, t_stack **stack_b)
{
	push_all_b(push, stack_a);
	while (*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest(push, stack_b);
		*stack_b = *stack_b;
	}
	if (!is_ordened(*stack_a))
		shift(push, stack_a);
}
