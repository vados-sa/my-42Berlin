/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 13:43:01 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/03 13:44:56 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack(&a, av + 1, ac == 2);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(a);
		else if (stack_len(a) == 3)
			sort_three(a);
		else
			big_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
