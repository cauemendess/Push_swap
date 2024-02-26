/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:46:44 by csilva-m          #+#    #+#             */
/*   Updated: 2024/02/26 15:46:45 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*top;

	if (*src == NULL)
		return ;
	top = *src;
	*src = top->next;
	if (*src)
		(*src)->prev = NULL;
	top->prev = NULL;
	if (*dest == NULL)
	{
		*dest = top;
		top->next = NULL;
		return ;
	}
	top->next = *dest;
	(*dest)->prev = top;
	*dest = top;
}

void	do_pa(t_push *push_swap)
{
	push(&push_swap->stack_b, &push_swap->stack_a);
}

void	do_pb(t_push *push_swap)
{
	push(&push_swap->stack_a, &push_swap->stack_b);
}
