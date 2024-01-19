#include "../includes/push_swap.h"

void	bubble_sort(t_push *push)
{
	t_stack *stack = push->stack_a;
	t_stack *stack_b = push->stack_b;
	while(stack)
	{
		if(stack > stack->next){
			do_pb(push);
			do_pb(push);

		}
		else
		{
			do_pb(push);
			do_pb(push);
		}
		
		stack = stack->next;
		print_stack(push->stack_a);
		print_stack(push->stack_b);
	}

}