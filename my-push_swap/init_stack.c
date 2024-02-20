#include "push_swap.h"

void	init_stack(t_stack **a, char **av, bool flag_ac_2);
void    add_to_stack(t_stack *a, int nbr);
int	    check_syntax(char *av);
int     check_duplicates(t_stack **a, int nbr);
void	error_exit(t_stack **a, char **av, bool flag_ac_2);
void    free_stack(t_stack **a);
void    free_split_av(char **av);

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

    if(!av)
        return ;
    i = 0;
    while(av[i])
        free(av[i++]);
    free (av);
}

void	error_exit(t_stack **a, char **av, bool flag_ac_2)
{
    free_stack(a);
    if (flag_ac_2)
        free_split_av(av);
	write(2, "Error\n", 6);
	exit(1);
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

int main(void)
{
    t_stack *a;

    a = NULL;
    char *av[5] = {av[0] = "\0", av[1] = "42", av[2] = "1999", av[3] = "-25", av[4] = NULL};
    init_stack(&a, av + 1, false);
    return (0);
}


/* FOR PYTHON TUTOR
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_node
{
    int                        value;
    struct s_node            *next;
}    t_node;

typedef struct s_stack
{
    t_node                    *top;
}    t_stack;


void    init_stack(t_stack **a, char **av, bool flag_ac_2);
void    error_exit(t_stack **a, char **av, bool flag_ac_2);
void    add_to_stack(t_stack *a, int nbr);
int        check_syntax(char *av);
int     check_duplicates(t_stack **a, int nbr);

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

void    error_exit(t_stack **a, char **av, bool flag_ac_2)
{
    free_stack(a);
    write(2, "Error\n", 6);
    exit(1);
}

int    check_syntax(char *av)
{
    int    i;

    i = 0;
    if ((av[i] == '-' || av[i] == '+') && !isdigit(av[i + 1]))
        return (1);
    if (av[i] == '-' || av[i] == '+')
        i++;
    while (av[i])
    {
        if (!isdigit(av[i]))
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

void    init_stack(t_stack **a, char **av, bool flag_ac_2)
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
        nbr = atoll(av[i]);
        if (nbr < -2147483648 || nbr > 2147483647)
            error_exit(a, av, flag_ac_2);
        if (check_duplicates(a, (int)nbr))
            error_exit(a, av, flag_ac_2);
        add_to_stack(*a, (int)nbr);
        i++;
    }
}

int main(void)
{
    t_stack *a;

    a = NULL;
    char *av[5] = {av[0] = "\0", av[1] = "A2", av[2] = "1999", av[3] = "-25", av[4] = NULL};
    init_stack(&a, av + 1, false);
    return (0);
}*/