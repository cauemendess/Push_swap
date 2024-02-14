#include "../includes/push_swap.h"


void	push_back(t_push *push, t_stack **stack_b)
{
	unsigned int	index;
	unsigned int	len_b;

	index = 0;
	len_b = get_stack_size(*stack_b);
	while (index < len_b)
	{
		do_pa(push);
		index++;
	}
}

void	radix(t_push *push, t_stack **stack_a, t_stack **stack_b, int bits)
{

	int i;
	i = 0;
	unsigned int index;
	unsigned int len_a;
	len_a = get_stack_size(*stack_a);

	while(i < bits)
	{
		index = 0;
		while(index < len_a)
		{
			if(((*stack_a)->index >> i) % 2 == 1)
				do_ra(push);
			else
				do_pb(push); 
			index++;
			(*stack_a) = (*stack_a);
		}
		push_back(push, stack_b);
		i++;
	}
}