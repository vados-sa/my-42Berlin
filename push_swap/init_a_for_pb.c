#include "push_swap.h"

void	init_nodes_a(t_stack **a, t_stack **b)
{
	find_index(*a);
	find_index(*b);
	set_target_for_a(*a, *b);
	push_cost_analisys_a(*a, *b);
	set_cheapest(*a);
}

/* For each node in A, this function interates through the nodes in B to find
the 'target_node'. The 'target_node' should be the the biggest node in B that
is still smaller than the node in A ("closest/biggest smaller").
'match_value' keeps track of the closest number to the node in A, so that the
next possible smaller nodes in B, with values < 'match_value' are not 
targeted. */
void set_target_for_a(t_stack *a, t_stack *b) // might be set to static
{
	t_node	*node_a;
	t_node	*node_b;
	t_node	*target_node;
	long	match_value;

	node_a = a->top;
	while (node_a)
	{
		node_b = b->top;
		match_value = LONG_MIN;
		while (node_b)
		{
			if (node_a->value > node_b->value && node_b->value > match_value)
			{
				match_value = node_b->value;
				target_node = node_b;
			}
			node_b = node_b->next;
		}
		if (match_value == LONG_MIN)
			node_a->target_node = find_max(b);
		else
			node_a->target_node = target_node;
		node_a = node_a->next;
	}
}

void	push_cost_analisys_a(t_stack *a, t_stack *b)  // might be set to static
{
	t_node	*current_a;
	int		len_a;
	int		len_b;

	current_a = a->top;
	len_a = stack_len(a);
	len_b = stack_len(b);
	while (current_a)
	{
		current_a->push_price = current_a->index;
		if (!current_a->above_median)
			current_a->push_price = len_a - current_a->index;
		if (current_a->target_node->above_median == true)
			current_a->push_price += current_a->target_node->index;
		else
			current_a->push_price += len_b - current_a->target_node->index;
		current_a = current_a->next;
	}
}