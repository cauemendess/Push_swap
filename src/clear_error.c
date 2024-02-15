/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:29:29 by csilva-m          #+#    #+#             */
/*   Updated: 2024/02/15 17:43:14 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (stack != NULL)
	{
		while (*stack)
		{
			temp = *stack;
			*stack = (*stack)->next;
			free(temp);
		}
		*stack = NULL;
	}
}

void	ft_finish(t_push *push_swap)
{
	if (push_swap->stack_a)
		free_stack(&push_swap->stack_a);
	if (push_swap->stack_a)
		free_stack(&push_swap->stack_b);
	if (push_swap->argv != NULL && push_swap->is_splited == TRUE)
		ft_freestr(push_swap->argv);
	free(push_swap);
	exit(0);
}

void	ft_clear_err(char *message, t_push *push_swap)
{
	ft_putendl_fd(message, 2);
	if (push_swap->stack_a)
		free_stack(&push_swap->stack_a);
	if (push_swap->stack_a)
		free_stack(&push_swap->stack_b);
	if (push_swap->argv != NULL && push_swap->is_splited == TRUE)
		ft_freestr(push_swap->argv);
	free(push_swap);
	exit(1);
}

void	ft_error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(1);
}

void	ft_freestr(char **str)
{
	size_t	index;

	index = 0;
	while (str[index] != NULL)
	{
		free(str[index]);
		index++;
	}
	free(str);
}
