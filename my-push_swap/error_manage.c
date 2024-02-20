#include "push_swap.h"

void	error_exit(t_stack **a, char **av, bool flag_ac_2)
{
    free_stack(a);
    if (flag_ac_2)
        free_split_av(av);
    write(2, "Error\n", 6);
    exit(1);
}

void    free_stack(t_stack **a)
{
    t_node  *current;
    t_node  *next;

    if (!*a || !a)
        return ;
    current = (*a)->top;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free (*a);
    *a = NULL;
}

void    free_split_av(char **av)
{
    int i;

    if(!av || !*av)
        return ;
    i = -1; // start at -1 so the placeholder at index 0 gets properly freed.
    while(av[i])
        free(av[i++]);
    free (av - 1); //adjusts for the extra space allocated for the placeholder at the beginning
}
