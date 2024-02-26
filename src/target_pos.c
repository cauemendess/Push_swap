/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:51:12 by csilva-m          #+#    #+#             */
/*   Updated: 2024/02/26 15:51:13 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_positon(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

int	get_target(t_stack **stack_a, int target, int b_index, int target_index)
{
	t_stack	*temp;

	temp = *stack_a;
	while (temp)
	{
		if (temp->index > b_index && temp->index < target_index)
		{
			target_index = temp->index;
			target = temp->pos;
		}
		temp = temp->next;
	}
	if (target_index != INT_MAX)
		return (target);
	temp = *stack_a;
	while (temp)
	{
		if (temp->index < target_index)
		{
			target_index = temp->index;
			target = temp->pos;
		}
		temp = temp->next;
	}
	return (target);
}

void	get_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	int		target;
	int		target_index;
	t_stack	*temp;

	target_index = INT_MAX;
	get_positon(stack_a);
	get_positon(stack_b);
	temp = *stack_b;
	target = 0;
	while (temp)
	{
		target = get_target(stack_a, target, temp->index, target_index);
		temp->target_pos = target;
		temp = temp->next;
	}
}
