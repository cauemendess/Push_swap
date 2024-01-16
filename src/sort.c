/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:42:03 by csilva-m          #+#    #+#             */
/*   Updated: 2024/01/16 16:54:52 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bubble_sort(t_push *push_swap)
{
	int sorted;
	sorted = 0;
	t_stack *cur = push_swap->stack_a;
	while(!sorted)
	{
		sorted = 1;
		while(cur != NULL && cur->next != NULL)
		{
			if(cur->value > cur->next->value)
			{
				sorted = 0;
				do_sa(push_swap);
				do_rra(push_swap);
			}
			cur = cur->next;
		}
	}
}
