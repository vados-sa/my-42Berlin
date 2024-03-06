/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_push_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 14:00:27 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/03 14:10:33 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_node *cheapest);
static void	rev_rotate_both(t_stack **a, t_stack **b, t_node *cheapest);
static void	prep_push(t_stack **stack, t_node *cheapest, char stack_name);

void	push_cheapest_a(t_stack **a, t_stack **b)
{
	t_node	*cheap_a;

	cheap_a = get_cheapest(*a);
	if (cheap_a->above_median && cheap_a->target_node->above_median)
		rotate_both(a, b, cheap_a);
	else if (!cheap_a->above_median && !cheap_a->target_node->above_median)
		rev_rotate_both(a, b, cheap_a);
	prep_push(a, cheap_a, 'a');
	prep_push(b, cheap_a->target_node, 'b');
	pb(*b, *a);
}

void	push_back_to_a(t_stack **b, t_stack **a)
{
	t_node	*b_node;

	b_node = (*b)->top;
	while ((*a)->top != b_node->target_node)
	{
		if (b_node->target_node->above_median)
			ra(*a);
		else
			rra(*a);
	}
	pa(*a, *b);
}

static void	rotate_both(t_stack **a, t_stack **b, t_node *cheapest)
{
	while ((*a)->top != cheapest && (*b)->top != cheapest->target_node)
		rr(*a, *b);
	find_index(*a);
	find_index(*b);
}

static void	rev_rotate_both(t_stack **a, t_stack **b, t_node *cheapest)
{
	while ((*a)->top != cheapest && (*b)->top != cheapest->target_node)
		rrr(*a, *b);
	find_index(*a);
	find_index(*b);
}

static void	prep_push(t_stack **stack, t_node *cheapest, char stack_name)
{
	while ((*stack)->top != cheapest)
	{
		if (stack_name == 'a')
		{
			if (cheapest->above_median)
				ra(*stack);
			else
				rra(*stack);
		}
		else if (stack_name == 'b')
		{
			if (cheapest->above_median)
				rb(*stack);
			else
				rrb(*stack);
		}
	}
}
