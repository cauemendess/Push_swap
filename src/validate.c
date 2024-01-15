/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:54:28 by csilva-m          #+#    #+#             */
/*   Updated: 2024/01/10 14:46:54 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool is_ordened(t_stack *stack)
{
    t_stack *temp;
    temp = stack;
    if (stack == NULL || stack->next == NULL)
        return true;
    while(temp->next != NULL)
    {
        if(temp->value > temp->next->value)
            return(false);
        temp = temp->next;
    }
    return(true);
}

bool have_duplicates(t_stack *stack)
{
	t_stack *temp;
	t_stack *runner;
	temp = stack;
	if (stack == NULL || stack->next == NULL)
        return false;
	while(temp->next != NULL)
	{
		runner = temp->next;
		while(runner->next != NULL)
		{
			if(temp->value == runner->value)
				return(true);
			runner = runner->next;
		}
		temp = temp->next;
	}
	return(false);
}

bool is_numbers(t_push *push_swap)
{
	int i;
	i = 0;
	while(push_swap->argv[i])
	{
		if(!ft_isdigit(push_swap->argv[i]))
			return(false);
		i++;
	}
	return(true);
}