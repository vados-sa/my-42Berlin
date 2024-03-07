/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:29:55 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/07 16:30:00 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;
	char	*instruction;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack(&a, av + 1, ac == 2);
	init_b(&b, &a);
	instruction = get_next_line(0);
	while (instruction)
	{
		apply_instructions(instruction, a, b);
		free (instruction);
		instruction = get_next_line(0);
	}
	checker(a, b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
