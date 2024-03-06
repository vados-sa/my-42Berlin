/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:09:01 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/03 14:09:28 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swap the first 2 elements at the top of stack.
Do nothing if there is only one or no elements. */
static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}
/* 'stack->top' access the top node of the stack.
   'stack->top->next' access the second node. */

/* Swap a. */
void	sa(t_stack *stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

/* Swap b. */
void	sb(t_stack *stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

/* sa and sb at the same time. */
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
