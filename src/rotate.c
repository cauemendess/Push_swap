/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:54:35 by csilva-m          #+#    #+#             */
/*   Updated: 2024/01/10 11:54:35 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    rotate(t_stack **stack)
{
    t_stack *cur;
    cur = *stack;
    while(cur->next != NULL)
        cur = cur->next;
    cur->next->prev = NULL;
    cur->prev = NULL;
    cur->next = *stack;
    (*stack)->prev = cur;
    *stack = cur;
}

void reverse_rotate(t_stack **stack)
{
    t_stack *cur;
    t_stack *new_next;
    cur = *stack;
    new_next = (*stack)->next;
    while(cur->next != NULL)
        cur = cur->next;
    cur->next = *stack;
    (*stack)->prev = cur;
    (*stack)->next->prev = NULL;
    (*stack)->next = NULL;
    *stack = new_next;
}