#include "push_swap.h"

void	init_stack(t_stack **a, char **av, bool flag_ac_2)
{
    int         i;
    long long   nbr;

    *a = malloc(sizeof(t_stack));
    if (!*a) // Check if the allocation was successful
        error_exit(a, av, flag_ac_2);
    (*a)->top = NULL; // Initialize top to NULL
    i = 0;
    while (av[i])
    {
        if (check_syntax(av[i]))
            error_exit(a, av, flag_ac_2);
        nbr = ft_atoll(av[i]);
        if (nbr < INT_MIN || nbr > INT_MAX)
            error_exit(a, av, flag_ac_2);
        if (check_duplicates(a, (int)nbr))
            error_exit(a, av, flag_ac_2);
        add_to_stack(*a, (int)nbr);
        i++;
    }
}

int	check_syntax(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '-' || av[i] == '+') && !ft_isdigit(av[i + 1]))
        return (1);
    if (av[i] == '-' || av[i] == '+')
        i++;
    while (av[i])
    {
		if (!ft_isdigit(av[i]))
    			return (1);
        i++;
	}	
	return (0);
}

int check_duplicates(t_stack **a, int nbr)
{
    t_node  *current;

    if (!(*a) || !(*a)->top)
        return (0);
    current = (*a)->top;
    while (current)
    {
        if (nbr == current->value)
            return (1);
        current = current->next;
    }
    return (0);
}

void    add_to_stack(t_stack *a, int nbr)
{
    t_node  *new_node;
    t_node  *last;

    new_node = malloc(sizeof(t_node));
    if (!new_node)
        return ;
    new_node->value = nbr;
    new_node->next = NULL;
    if (!a->top)
        a->top = new_node;
    else
    {
        last = a->top;
        while (last->next)
            last = last->next;
        last->next = new_node;
    }
}

/* int main(void)
{
    t_stack *a;

    a = NULL;
    char *av[5] = {av[0] = "\0", av[1] = "42", av[2] = "1999", av[3] = "-25", av[4] = NULL};
    init_stack(&a, av + 1, false);
    return (0);
} */