/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:50:21 by csilva-m          #+#    #+#             */
/*   Updated: 2024/02/26 15:50:22 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_move(t_push *push, int cost_a, int cost_b)
{
	move_both(push, &cost_a, &cost_b);
	move_a(push, &cost_a);
	move_b(push, &cost_b);
	do_pa(push);
}

void	move_a(t_push *push, int *cost_a)
{
	if (*cost_a > 0)
	{
		while (*cost_a > 0)
		{
			do_ra(push);
			(*cost_a)--;
		}
	}
	else
	{
		while (*cost_a < 0)
		{
			do_rra(push);
			(*cost_a)++;
		}
	}
}

void	move_b(t_push *push, int *cost_b)
{
	if (*cost_b > 0)
	{
		while (*cost_b > 0)
		{
			do_rb(push);
			(*cost_b)--;
		}
	}
	else
	{
		while (*cost_b < 0)
		{
			do_rrb(push);
			(*cost_b)++;
		}
	}
}

void	move_both(t_push *push, int *cost_a, int *cost_b)
{
	if (*cost_a < 0 && *cost_b < 0)
	{
		while (*cost_a && *cost_b)
		{
			(*cost_a)++;
			(*cost_b)++;
			do_rrr(push);
		}
	}
	else if (*cost_a > 0 && *cost_b > 0)
	{
		while (*cost_a && *cost_b)
		{
			(*cost_a)--;
			(*cost_b)--;
			do_rr(push);
		}
	}
}
