/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:02:41 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/03 14:05:06 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		from_to(t_stack *src, t_stack *dest, const char *opr);
static t_node	*pop_op(t_stack *stack);
static void		push_op(t_stack *stack, t_node *element);

/* Push A. */
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	from_to(stack_b, stack_a, "pa\n");
}

/* Push B. */
void	pb(t_stack *stack_b, t_stack *stack_a)
{
	from_to(stack_a, stack_b, "pb\n");
}

/*Take the first element at the top of source(b) stack and put it at the
top of destination(a) stack. Do nothing if the src stack is empty*/
static void	from_to(t_stack *src, t_stack *dest, const char *opr)
{
	t_node	*top_elem;

	if (!src || !src->top)
		return ;
	top_elem = pop_op(src);
	push_op(dest, top_elem);
	if (opr)
		write(1, opr, ft_strlen(opr));
}

/* Removes the first element of the stack. */
static t_node	*pop_op(t_stack *stack)
{
	t_node	*first;

	if (!stack || !stack->top)
		return (NULL);
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	return (first);
}

/* Adds a new element to the top of the stack. */
static void	push_op(t_stack *stack, t_node *element)
{
	if (!stack || !element)
		return ;
	element->next = stack->top;
	stack->top = element;
}
