/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:55:33 by csilva-m          #+#    #+#             */
/*   Updated: 2024/01/08 17:27:17 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;
	if(!*stack || (*stack)->next != NULL)
		return;
	first = *stack;
	second = (*stack)->next;
	
}


void do_sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sb\n");
}

void do_sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

