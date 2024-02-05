#include "../includes/push_swap.h"

void insertion_sort(t_push *push)
{

	t_stack *cur;
	cur = push->stack_a;
	while(cur)
	{
		if(cur == find_max_node(push->stack_a))
		{
			ft_printf("%d\n", cur->value);
		}
		cur = cur->next;
	}
}