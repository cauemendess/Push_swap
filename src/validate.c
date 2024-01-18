/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:54:28 by csilva-m          #+#    #+#             */
/*   Updated: 2024/01/18 17:01:08 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool is_ordened(t_stack *stack)
{
    t_stack *temp;
    temp = stack;
    if (stack == NULL || stack->next == NULL)
        return TRUE;
    while(temp->next != NULL)
    {
        if(temp->value > temp->next->value)
            return(FALSE);
        temp = temp->next;
    }
    return(TRUE);
}

t_bool have_duplicates(t_stack *stack)
{
	t_stack *temp;
	t_stack *runner;
	temp = stack;
	if (stack == NULL || stack->next == NULL)
        return FALSE;
	while(temp->next != NULL)
	{
		runner = temp->next;
		while(runner->next != NULL)
		{
			if(temp->value == runner->value)
				return(TRUE);
			runner = runner->next;
		}
		temp = temp->next;
	}
	return(FALSE);
}
