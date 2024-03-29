/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:46:32 by csilva-m          #+#    #+#             */
/*   Updated: 2024/02/26 15:46:33 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*get_stack_last(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = (t_stack *)stack->next;
	return (stack);
}

t_stack	*ft_stack_new(int content)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		ft_printf("Erro");
	node->value = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_back(t_stack **stack, t_stack *stack_new)
{
	t_stack	*tail;

	if (!stack)
		return ;
	if (!*stack)
	{
		*stack = stack_new;
		return ;
	}
	tail = get_stack_last(*stack);
	tail->next = stack_new;
	stack_new->prev = tail;
}

int	get_stack_size(t_stack *stack)
{
	int		res;
	t_stack	*temp;

	res = 0;
	temp = stack;
	while (temp != NULL)
	{
		temp = temp->next;
		res++;
	}
	return (res);
}
