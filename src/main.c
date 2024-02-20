/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:59:07 by csilva-m          #+#    #+#             */
/*   Updated: 2024/02/15 17:59:07 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack_a)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp != NULL)
	{
		ft_printf("value: %d ", temp->value);
		ft_printf("index: %d\n", temp->index);
		temp = temp->next;
	}
}

void	push_swap(t_push *push)
{
	if (push->size_a == 2)
	{
		do_sa(push);
		ft_finish(push);
	}
	if (push->size_a == 3)
		sort_3(push);
	else if (push->size_a < 50 && push->size_a > 3)
		small_sort(push, &push->stack_a, &push->stack_b);
	else
		radix(push, &push->stack_a, &push->stack_b, push->bits);
}

int	main(int argc, char **argv)
{
	t_push	*push;

	push = init_all(argc, argv);
	init_stack(push);
	assign_index(push);
	validate(push);
	if (!is_ordened(push->stack_a))
		push_swap(push);
	ft_finish(push);
}
