
#include "checker_bonus.h"

t_bool	is_ordened(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (stack == NULL || stack->next == NULL)
		return (TRUE);
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}

t_bool	have_duplicates(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*runner;

	temp = stack;
	if (stack == NULL || stack->next == NULL)
		return (FALSE);
	while (temp->next != NULL)
	{
		runner = temp->next;
		while (runner)
		{
			if (temp->value == runner->value)
				return (TRUE);
			runner = runner->next;
		}
		temp = temp->next;
	}
	return (FALSE);
}

t_bool	is_numbers(t_push *push)
{
	int	i;
	int	j;

	i = 0;
	while (i < push->argc - 1)
	{
		j = 0;
		if (!push->argv[i])
			return (FALSE);
		if (push->argv[i][j] == '+' || push->argv[i][j] == '-')
			j++;
		while (push->argv[i][j])
		{
			if (!ft_isdigit(push->argv[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

void	validate(t_push *push)
{
	if (have_duplicates(push->stack_a))
		ft_clear_err("Error", push);
	if (!is_numbers(push))
		ft_clear_err("Error", push);
}