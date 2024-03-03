/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:56:50 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/03 13:59:28 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack **a, char **av, bool flag_ac_2)
{
	free_stack(a);
	if (flag_ac_2)
		free_split_av(av);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack **stack)
{
	t_node	*current;
	t_node	*next;

	if (!*stack || !stack)
		return ;
	current = (*stack)->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free (*stack);
	*stack = NULL;
}

/*
*start at -1 so the placeholder at index 0 gets properly freed.
*adjusts for the extra space allocated for the placeholder at the beginning
*/
void	free_split_av(char **av)
{
	int	i;

	if (!av || !*av)
		return ;
	i = -1;
	while (av[i])
		free(av[i++]);
	free (av - 1);
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

int	check_duplicates(t_stack **a, int nbr)
{
	t_node	*current;

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
