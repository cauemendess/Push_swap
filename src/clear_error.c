/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:29:29 by csilva-m          #+#    #+#             */
/*   Updated: 2024/01/10 15:40:44 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack *cur;
	cur = *stack;
	t_stack *next;
	while(cur != NULL)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*stack = NULL;
}


void	ft_finish(t_push *push_swap)
{
	if(push_swap->stack_a != NULL)
		free_stack(&push_swap->stack_a);
	if(push_swap->argv != NULL)
		ft_freestr(push_swap->argv);
	free(push_swap);
	exit(0);
}


void	ft_error(char *message)
{
	ft_printf("%s\n", message);
	exit(1);
}
void	ft_freestr(char **str)
{
	
	if (!str)
		return ;
	int i;
	i = 0;
	while (str[i])
	{
		i++;
		free(str[i]);
	}
	free(str);
}