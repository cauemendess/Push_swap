#include "../includes/push_swap.h"


void	push_all_b(t_push *push, t_stack **stack_a)
{
	int i;
	i = 0;

	int stack_size;
	stack_size = get_stack_size(*stack_a) / 2;
	while(get_stack_size(*stack_a) > stack_size)
	{
		if((*stack_a)->index < stack_size)
			do_pb(push);
		else
			do_ra(push);
		i++;
	}

	while(get_stack_size(*stack_a) > 3)
	{
		do_pb(push);
	}
	sort_3(push);
}


void	get_position(t_stack *stack)
{
	t_stack *temp;
	temp = stack;
	int i;
	i = 0;
	while(temp)
	{
		temp->position = i;
		temp = temp->next;
		i++;
	}
}

//int	get_target(t_stack *stack_a, int target_pos)
//{

//}



//void	radix(t_push *push, t_stack **stack_a, t_stack **stack_b, int bits)
//{

//	int i;
//	int index;
//	unsigned int len_a;
//	len_a = push->size_a;

//	while(i < bits)
//	{
//		index = 0;
//		while(index < len_a)
//		{
//			if((*stack_a)->index >> i % 2 == 0)
//				do_ra(push);
//			else
//				do_pb(push);
//			index++;
//			(*stack_a) = (*stack_a);
//		}

//		i++;
//	}

//}