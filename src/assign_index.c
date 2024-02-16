/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:37:39 by csilva-m          #+#    #+#             */
/*   Updated: 2024/02/16 11:28:09 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_index(t_push *push)
{
	t_stack	*stack;
	int		index;

	stack = push->stack_a;
	while (stack)
	{
		index = 0;
		while (index < push->size_a)
		{
			if (stack->value == push->argv_sort[index])
			{
				stack->index = index;
			}
			index++;
		}
		stack = stack->next;
	}
	free(push->argv_sort);
}

void	sort_tab(int *tab, int size)
{
	int	i;
	int	tmp;
	int	position;

	i = 0;
	while (i < size - 1)
	{
		position = 0;
		while (position < size - 1)
		{
			if (tab[position] > tab[position + 1])
			{
				tmp = tab[position];
				tab[position] = tab[position + 1];
				tab[position + 1] = tmp;
			}
			position++;
		}
		i++;
	}
}

int	*tab_argv(t_push *push)
{
	int	i;
	int	*res;

	i = 0;
	res = malloc(sizeof(int) * push->size_a);
	while (push->argv[i])
	{
		res[i] = ft_atoi(push->argv[i]);
		i++;
	}
	sort_tab(res, push->size_a);
	return (res);
}
