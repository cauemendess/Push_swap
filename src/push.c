/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:53:23 by csilva-m          #+#    #+#             */
/*   Updated: 2024/01/04 17:53:04 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	push(t_stack **src, t_stack **dest)
{
	t_stack *top;
	if(*src == NULL)
		return;
	top = *src;
	*src = top->next;
	if(*src)
		(*src)->prev = NULL;
	top->prev = NULL;
	if(*dest == NULL)
	{
		*dest = top;
		top->next = NULL;
		return ;
	}
	top->next = *dest;
	(*dest)->prev = top;
	*dest = top;
}

void move_top_to_stack_b(t_stack **stack_a, t_stack **stack_b) {
    if (!stack_a || !stack_b || !*stack_a) {
        return; // Verifica se as pilhas são válidas e não estão vazias
    }

    // Remove o primeiro elemento da stack_a
    t_stack *top = *stack_a;
    *stack_a = top->next;
    if (*stack_a) {
        (*stack_a)->prev = NULL;
    }

    // Adiciona o elemento removido à stack_b
    top->next = NULL;
    top->prev = NULL;
    add_back(stack_b, top);
}