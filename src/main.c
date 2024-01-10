/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:52:28 by csilva-m          #+#    #+#             */
/*   Updated: 2024/01/04 17:52:28 by csilva-m         ###   ########.fr       */
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
    node->prev = NULL;
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
    stack_new->prev = tail;
}


// Ignore essa função por enquanto...
void print_stack(t_stack *stack_a)
{
    t_stack *temp;
    temp = stack_a;
    while(temp != NULL)
    {
        ft_printf("value: %d\n", temp->value);
        temp = temp->next;
    }
}


t_stack     *init_stack(int argc, char **argv)
{
    if(argc < 2)
    {
        ft_printf("Error");
    }
	int i = 1;
	int el;
	t_stack *stack_a;

	while (i < argc)
	{
		el = ft_atoi(argv[i]);
        if(i == 1)
            stack_a = ft_stack_new(el);
        else
		    add_back(&stack_a, ft_stack_new(el));
		i++;
	}
    return(stack_a);
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



int get_stack_size(t_stack *stack)
{
    int res = 0;
    t_stack *temp;
    temp = stack;
    while(temp != NULL)
    {
        temp = temp->next;
        res++;
    }
    return(res);
}



int	main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_b = NULL;
	stack_a = init_stack(argc, argv);
    // ft_printf("Antes do push\n");
    // ft_printf("===================\n");
    // print_stack(stack_a);
    // ft_printf("===================\n");
    // ft_printf("Depois do push\n");
    // ft_printf("===================\n");
    
    // push(&stack_a, &stack_b);

    // push(&stack_a, &stack_b);
    // push(&stack_a, &stack_b);



    ft_printf("Antes do swap\n");
    ft_printf("===================\n");
    print_stack(stack_a);
    ft_printf("===================\n");
    ft_printf("Depois do swap\n");
    ft_printf("===================\n");

    swap(&stack_a);
    ft_printf("Stack a\n");
    ft_printf("===================\n");
    print_stack(stack_a);
    ft_printf("===================\n");
    ft_printf("Stack b\n");
    ft_printf("===================\n");
    print_stack(stack_b);


}
