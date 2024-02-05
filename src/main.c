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

void    print_stack(t_stack *stack_a)
{
    t_stack *temp;
    temp = stack_a;
    while(temp != NULL)
    {
        ft_printf("value: %d ", temp->value);
        ft_printf("index: %d\n", temp->index);
        temp = temp->next;
    }
}


int	main(int argc, char **argv)
{
    t_push *push_swap;
    push_swap = init_all(argc, argv);
    init_stack(push_swap);
    validate(push_swap);
    assign_index(push_swap);
    if(push_swap->size_a == 3)
        sort_3(push_swap);
    else
        insertion_sort(push_swap);
    print_stack(push_swap->stack_a);
    ft_finish(push_swap);

}
