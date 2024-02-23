/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:38:17 by csilva-m          #+#    #+#             */
/*   Updated: 2024/02/23 18:25:59 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	push_all_b(t_push *push, t_stack **stack_a)
{
	int i;
	i = 0;

	int stack_size;
	stack_size = get_stack_size(*stack_a) / 2;
	while(get_stack_size(*stack_a) > stack_size)
	{
		if((*stack_a)->index < stack_size)
			do_pb(push);
		else
			do_ra(push);
		i++;
	}

	while(get_stack_size(*stack_a) > 3)
		do_pb(push);
	sort_3(push);
}

void	get_positon(t_stack **stack)
{
	t_stack *temp;
	int	i;
	i = 0;
	temp = *stack;
	while(temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

//int	get_target(t_stack **stack_a)
//{

//}

//void	get_target_pos(t_stack **stack_a, t_stack **stack_b)
//{
//	int target;
//	t_stack *temp;
	
//	get_positon(stack_a);
//	get_positon(stack_b);
//	temp = *stack_b;
//	target = 0;
//	while(temp)
//	{
//		target = get_target(stack_a);
//	}
	
//}


void	sort(t_push *push, t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_b;
	push_all_b(push, stack_a);
	get_positon(stack_a);
	get_positon(stack_b);
	get_target_pos(stack_a, stack_b);
	
}
