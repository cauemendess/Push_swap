#include "../includes/push_swap.h"


void	do_move(t_push *push, int cost_a, int cost_b)
{
    move_both(push, &cost_a, &cost_b);
    move_a(push, &cost_a);
    move_b(push, &cost_b);
    do_pa(push); 
}


void move_a(t_push *push, int *cost)
{
    while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(push);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(push);
			(*cost)++;
		}
	}
}

void move_b(t_push *push, int *cost)
{

    while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(push);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(push);
			(*cost)++;
		}
	}
	
}

void move_both(t_push *push, int *cost_a, int *cost_b)
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
    else if(*cost_a > 0 && *cost_b > 0)
    {
        while (*cost_a && *cost_b)
        {
            (*cost_a)--;
            (*cost_b)--;
            do_rr(push);
        }
    }
}
