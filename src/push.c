/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:53:23 by csilva-m          #+#    #+#             */
/*   Updated: 2024/01/03 18:28:01 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	push(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *temp;
	if(stack_a == NULL)
		return;
	temp = stack_a->next;
	stack_a->next = stack_b;
	stack_b = stack_a;
	stack_a = temp;
}