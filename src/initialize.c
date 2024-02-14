#include "../includes/push_swap.h"

long	ft_atol(const char *nptr)
{
	long	res;
	long	sig;
	int		i;

	res = 0;
	i = 0;
	sig = 1;
	while ((nptr[i] == 32) || ((nptr[i] >= 9) && (nptr[i] <= 13)))
	{
		i++;
	}
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sig *= -1;
		i++;
	}
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		res = res * 10;
		res = res + nptr[i] - '0';
		i++;
	}
	return (res * sig);
}

t_push	*init_all(int argc, char **argv)
{
	t_push	*push_swap;

	push_swap = malloc(sizeof(t_push));
	push_swap->argc = argc;
	push_swap->argv = argv;
	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
	push_swap->argv_sort = NULL;
	push_swap->is_splited = FALSE;
	push_swap->size_a = 0;
	if (argc == 2)
	{
		push_swap->argv = ft_split(argv[1], ' ');
		push_swap->is_splited = TRUE;
	}
	else
		push_swap->argv = ++argv;
	return (push_swap);
}

void	init_stack(t_push *push_swap)
{
	int	i;
	int	el;

	i = 0;
	if (push_swap->argc < 2)
		ft_error("Error");
	while (push_swap->argv[i])
	{
		if (ft_atol(push_swap->argv[i]) > INT_MAX
			|| ft_atol(push_swap->argv[i]) < INT_MIN)
			ft_clear_err("Error", push_swap);
		el = ft_atoi(push_swap->argv[i]);
		add_back(&push_swap->stack_a, ft_stack_new(el));
		i++;
	}
	push_swap->size_a = get_stack_size(push_swap->stack_a);
	push_swap->argv_sort = tab_argv(push_swap);
}
