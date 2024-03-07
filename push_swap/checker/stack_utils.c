
#include "checker.h"

void	init_stack(t_stack **a, char **av, bool flag_ac_2)
{
	int			i;
	long long	nbr;

	*a = malloc(sizeof(t_stack));
	if (!*a)
		error_exit(a, av, flag_ac_2);
	(*a)->top = NULL;
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
	if (flag_ac_2)
		free_split_av(av);
}

void	add_to_stack(t_stack *a, int nbr)
{
	t_node	*new_node;
	t_node	*last;

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

/* int	stack_sorted(t_stack *a)
{
	t_node	*current;

	if (!a || !a->top || !a->top->next)
		return (1);
	current = a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
} */
/* 
int	stack_len(t_stack *stack)
{
	int		i;
	t_node	*current;

	i = 0;
	current = stack->top;
	while (current)
	{
		current = current -> next;
		i++;
	}
	return (i);
} */
