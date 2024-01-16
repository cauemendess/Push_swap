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

t_stack	*get_stack_last(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = (t_stack *)stack->next;
	return (stack);
}

t_stack	*ft_stack_new(int content)
{
	t_stack *node;
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

void    init_stack(t_push* push_swap)
{
    if(push_swap->argc < 2)
    {
        ft_error("Erro2");
    }
	int i;
    i = 0;
	int el;
    
	while (push_swap->argv[i])
	{
	    el = ft_atoi(push_swap->argv[i]);
		add_back(&push_swap->stack_a, ft_stack_new(el));
		i++;
	}
    push_swap->size_a = get_stack_size(push_swap->stack_a);
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


t_push *init_all(int argc, char **argv)
{
    t_push *push_swap;
    push_swap = malloc(sizeof(t_push));
    push_swap->argc = argc;
    push_swap->argv = argv;
    push_swap->stack_a = NULL;
    push_swap->stack_b = NULL;
    push_swap->is_splited = false;
    push_swap->size_a = 0;
    if(argc == 2)
    {
        push_swap->argv = ft_split(argv[1], ' ');
        push_swap->is_splited = true;
    }
    else
        push_swap->argv = ++argv;
    return(push_swap);
}



int	main(int argc, char **argv)
{
    t_push *push_swap;
    push_swap = init_all(argc, argv);
    init_stack(push_swap);
    if(have_duplicates(push_swap->stack_a))
    {
        free_stack(&push_swap->stack_a);
        ft_error("Erro1");
    }
    bubble_sort(push_swap);
    print_stack(push_swap->stack_a);
    //ft_printf("Init a and b\n");
    //ft_printf("===================\n");
    //print_stack(push_swap->stack_a);
    //ft_printf("===================\n");
    //ft_printf("Exec ");
    //do_sa(push_swap);
    //ft_printf("===================\n");
    //print_stack(push_swap->stack_a);

    //ft_printf("===================\n");
    //ft_printf("Exec ");
    //do_pb(push_swap);
    //do_pb(push_swap);
    //do_pb(push_swap);
    //ft_printf("===================\n");
    //ft_printf("Stack A\n");
    //ft_printf("===================\n");
    //print_stack(push_swap->stack_a);
    //ft_printf("===================\n");
    //ft_printf("Stack B\n");
    //ft_printf("===================\n");
    //print_stack(push_swap->stack_b);

    //ft_printf("===================\n");
    //ft_printf("Exec ");
    //do_ra(push_swap);
    //do_rb(push_swap);
    //ft_printf("===================\n");
    //ft_printf("Stack A\n");
    //ft_printf("===================\n");
    //print_stack(push_swap->stack_a);
    //ft_printf("===================\n");
    //ft_printf("Stack B\n");
    //ft_printf("===================\n");
    //print_stack(push_swap->stack_b);

    //ft_printf("===================\n");
    //ft_printf("Exec ");
    //do_rra(push_swap);
    //do_rrb(push_swap);
    //ft_printf("===================\n");
    //ft_printf("Stack A\n");
    //ft_printf("===================\n");
    //print_stack(push_swap->stack_a);
    //ft_printf("===================\n");
    //ft_printf("Stack B\n");
    //ft_printf("===================\n");
    //print_stack(push_swap->stack_b);

    ft_finish(push_swap);

}

