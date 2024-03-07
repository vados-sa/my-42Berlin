/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:50:33 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/07 16:31:54 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_strcmp(char *s1, char *s2);
static void	error(t_stack **a, t_stack **b);

static void	error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	init_b(t_stack **b, t_stack **a)
{
	*b = malloc(sizeof(t_stack));
	if (!*b)
		error(a, b);
	(*b)->top = NULL;
}

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2
		&& *s1)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void	apply_instructions(char *instruct, t_stack *a, t_stack *b)
{
	if (ft_strcmp(instruct, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(instruct, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(instruct, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(instruct, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(instruct, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(instruct, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(instruct, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(instruct, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(instruct, "rrr\n") == 0)
		rrr(a, b);
	else if (ft_strcmp(instruct, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(instruct, "pb\n") == 0)
		pb(b, a);
	else
		error(&a, &b);
}

void	checker(t_stack *a, t_stack *b)
{
	if (stack_sorted(a) && b->top == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
