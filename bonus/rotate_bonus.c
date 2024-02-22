#include "checker_bonus.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*new_last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	new_last = *stack;
	while (new_last->next != NULL)
		new_last = new_last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	new_last->next = first;
	first->prev = new_last;
	first->next = NULL;
}

void	do_ra(t_push *push_swap)
{
	rotate(&push_swap->stack_a);
}

void	do_rb(t_push *push_swap)
{
	rotate(&push_swap->stack_b);
}

void	do_rr(t_push *push_swap)
{
	rotate(&push_swap->stack_a);
	rotate(&push_swap->stack_b);
}
