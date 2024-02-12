#include "../includes/push_swap.h"

t_push		*init_all(int argc, char **argv)
{
    t_push *push_swap;
    push_swap = malloc(sizeof(t_push));
    push_swap->argc = argc;
    push_swap->argv = argv;
    push_swap->stack_a = NULL;
    push_swap->stack_b = NULL;
    push_swap->argv_sort = NULL;
    push_swap->is_splited = FALSE;
    push_swap->size_a = 0;
    if(argc == 2)
    {
        push_swap->argv = ft_split(argv[1], ' ');
        push_swap->is_splited = TRUE;
    }
    else
        push_swap->argv = ++argv;
    return(push_swap);
}


void    init_stack(t_push *push_swap)
{
    if(push_swap->argc < 2)
    {
        ft_error("ErroY");
    }
	int i;
    i = 0;
	int el;
    
	while (push_swap->argv[i])
	{
	    el = ft_atoi(push_swap->argv[i]);
		add_back(&push_swap->stack_a, ft_stack_new(el));
		i++;
	}
    push_swap->size_a = get_stack_size(push_swap->stack_a);
    push_swap->argv_sort = tab_argv(push_swap);
}

