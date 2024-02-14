#include "../includes/push_swap.h"

int	get_target(t_stack *stack_a, int b_index);




void	get_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *temp;

	int size_a;
	int size_b;
	size_a = get_stack_size(stack_a);
	size_b = get_stack_size(stack_b);
	while(temp)
	{
		if(temp->position <= size_a / 2)
			temp->cost_a = temp->position;
		else
			temp->cost_a = (size_a - temp->position) * -1;

		if(temp->position <= size_b / 2)
			temp->cost_b = temp->position;
		else
			temp->cost_b = (size_b - temp->position) * -1;
		
		temp = temp->next;
	}
} 



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
		do_pb(push);
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


void update_target(t_stack *stack_a, t_stack *stack_b)
{
	get_position(stack_a);
	get_position(stack_b);
	while(stack_b)
	{
		stack_b->target = get_target(stack_a, stack_b->index);
		stack_b = stack_b->next;
	}
}

int	get_min(t_stack *stack)
{
	int smaller;
	t_stack *target;
	target = stack;
	smaller = stack->index;
	while(stack)
	{

		if(stack->index < smaller)
		{
			smaller = stack->index;
			target = stack;
		}
		stack = stack->next;
	}
	return(target->position);

}


int	get_target(t_stack *stack_a, int b_index)
{
	int target_index;

	int target_pos = -1;
	target_index = INT_MAX;
	t_stack *temp;
	temp = stack_a;
	while(temp)
	{
		if(temp->index > b_index && temp->index < target_index)
		{
			target_index = temp->index;
			target_pos = temp->position;
		}
		temp = temp->next;
	}
	if(target_pos == -1)
		return(get_min(stack_a));

	return(target_pos);

}

void sort(t_push *push, t_stack **stack_a, t_stack **stack_b)
{
	push_all_b(push, stack_a);
	sort_3(push);
	while(*stack_b)
	{
		update_target(*stack_a, *stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(push);

	}

}

void	do_cheapest_move(t_push *push)
{
	t_stack *temp;

	int cheap;
	int cost_a;
	int cost_b;
	cheap = INT_MAX;

	while(temp)
	{
		if(ft_abs(temp->cost_a) + ft_abs(temp->cost_b) < cheap)
		{
			cheap = ft_abs(temp->cost_b) + ft_abs(temp->cost_a);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	do_move(push, cost_a, cost_b);
}



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