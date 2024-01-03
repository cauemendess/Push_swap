#include "../includes/push_swap.h"

t_stack *ft_stack_new(int content)
{
    t_stack *node;
    return(node);
}

// void add_back(t_stack **stack, t_stack *new)
// {
// }

void init_all(int argc, char **argv)
{
    int i = 1;
    int el;
    t_stack **a;
    while(i < argc)
    {
        el = ft_atoi(argv[i]);
        ft_printf("%d", el);
        add_back(&a ,ft_stack_new(el));
        i++;
    }
}

int main(int argc, char **argv)
{
    ft_printf("%d\n", argc);
    init_all(argc, argv);
    return(0);
}