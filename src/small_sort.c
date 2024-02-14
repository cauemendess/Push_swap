#include "../includes/push_swap.h"

static int	find_min_node(t_stack *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

void	small_sort(t_push *push, t_stack **stack_a, t_stack **stack_b)
{
	int min_node;
	int len = get_stack_size(*stack_a);
	t_stack *temp;
	while (len > 3)
	{
		temp = *stack_a;
		min_node = find_min_node(*stack_a);

		while (temp)
		{
			if (temp->index == min_node)
			{
				do_pb(push);
				break ;
			}
			if (min_node < (len + 1) / 2)
				do_ra(push);
			else
				do_rra(push);
			temp = *stack_a;
		}
		len--;
	}

	sort_3(push);
	while (*stack_b)
		do_pa(push);
}