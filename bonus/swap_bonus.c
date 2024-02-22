#include "checker_bonus.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	if (second->next != NULL)
		second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	*stack = second;
}

void	do_sa(t_push *push_swap)
{
	swap(&push_swap->stack_a);
}

void	do_sb(t_push *push_swap)
{
	swap(&push_swap->stack_b);
}

void	do_ss(t_push *push_swap)
{
	swap(&push_swap->stack_a);
	swap(&push_swap->stack_b);
}