#include "push_swap.h"

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
		if(b_node->target_node->above_median)
			ra(*a);
		else
			rra(*a);
	}
	pa(*a, *b);
}

void	rotate_both(t_stack **a, t_stack **b, t_node *cheapest) // might be set to static
{
	while ((*a)->top != cheapest && (*b)->top != cheapest->target_node)
		rr(*a, *b);
	find_index(*a);
	find_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_node *cheapest) // might be set to static
{
	while ((*a)->top != cheapest && (*b)->top != cheapest->target_node)
		rrr(*a, *b);
	find_index(*a);
	find_index(*b);
}

void	prep_push(t_stack **stack, t_node *cheapest, char stack_name) // might be set to static
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