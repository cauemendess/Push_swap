/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:51:16 by csilva-m          #+#    #+#             */
/*   Updated: 2024/02/26 15:51:17 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		size_a;
	int		size_b;

	temp = *stack_b;
	size_a = get_stack_size(*stack_a);
	size_b = get_stack_size(*stack_b);
	while (temp)
	{
		if (temp->pos < size_b / 2)
			temp->cost_b = temp->pos;
		else
			temp->cost_b = (size_b - temp->pos) * -1;
		if (temp->target_pos < size_a / 2)
			temp->cost_a = temp->target_pos;
		else
			temp->cost_a = (size_a - temp->target_pos) * -1;
		temp = temp->next;
	}
}

void	do_cheapest(t_push *push, t_stack **stack_b)
{
	t_stack	*temp;
	int		cheap;
	int		cost_a;
	int		cost_b;

	cheap = INT_MAX;
	temp = *stack_b;
	while (temp)
	{
		if (ft_abs(temp->cost_a) + ft_abs(temp->cost_b) < ft_abs(cheap))
		{
			cheap = ft_abs(temp->cost_a) + ft_abs(temp->cost_b);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	do_move(push, cost_a, cost_b);
}
