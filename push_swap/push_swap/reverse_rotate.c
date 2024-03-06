/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:05:29 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/03 14:07:03 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack);

/*Shift down all elements of the stack by 1.
The last element becomes the first one.*/
static void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*prev_to_last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	last = stack->top;
	prev_to_last = NULL;
	while (last->next)
	{
		prev_to_last = last;
		last = last->next;
	}
	if (prev_to_last)
	{
		prev_to_last->next = NULL;
		last->next = stack->top;
		stack->top = last;
	}
}

/* Reverse rotate A. */
void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

/* Reverse rotate B. */
void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

/* rra and rrb at the same time. */
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
