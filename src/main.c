/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/01/03 14:30:47 by csilva-m          #+#    #+#             */
/*   Updated: 2024/01/03 14:30:47 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdbool.h>


t_stack	*get_stack_last(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = (t_stack *)stack->next;
	return (stack);
}


t_stack	*ft_stack_new(int content)
{
	t_stack *node;
	node = malloc(sizeof(t_stack));
	if (!node)
		ft_printf("Erro");
	node->value = content;
	node->next = NULL;
	return (node);
}

void	add_back(t_stack **stack, t_stack *stack_new)
{
    t_stack *tail;
	if (!stack)
		return ;
	if (!*stack)
    {
		*stack = stack_new;
        return;
    }
    tail = get_stack_last(*stack);
    tail->next = stack_new;
}

void print_stack(t_stack *a)
{
    t_stack *temp;
    temp = a;
    while(temp != NULL)
    {
        ft_printf("value: %d\n", temp->value);
        temp = temp->next;
    }
}

t_stack     *init_stack(int argc, char **argv)
{
	int i = 1;
	int el;
	t_stack *a;
	while (i < argc)
	{
		el = ft_atoi(argv[i]);
        if(i == 1)
            a = ft_stack_new(el);
        else
		    add_back(&a, ft_stack_new(el));
		i++;
	}
    return(a);
}


bool is_ordened(t_stack *stack_a)
{
    t_stack *temp;
    temp = stack_a;
    if (stack_a == NULL || stack_a->next == NULL)
        return true;
    while(temp->next != NULL)
    {
        if(temp->value > temp->next->value)
            return(false);
        temp = temp->next;
    }
    return(true);
}


int	main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    stack_b = NULL;
	stack_a = init_stack(argc, argv);
    push(stack_a, stack_b);
    print_stack(stack_a);

}
