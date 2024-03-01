#include "push_swap.h"

static void set_target_for_a(t_stack *a, t_stack *b);
static void	set_target_for_b(t_stack *b, t_stack *a);
static void	push_cost_analisys(t_stack *stack, t_stack *target_stack);

void	init_nodes_a(t_stack **a, t_stack **b)
{
	find_index(*a);
	find_index(*b);
	set_target_for_a(*a, *b);
	push_cost_analisys(*a, *b);
	set_cheapest(*a);
}

void	init_nodes_b(t_stack **b, t_stack **a)
{
	find_index(*b);
	find_index(*a);
	set_target_for_b(*b, *a);
}

/* For each node in A, this function interates through the nodes in B to find
the 'target_node'. The 'target_node' should be the the biggest node in B that
is still smaller than the node in A ("closest/biggest smaller").
'match_value' keeps track of the closest number to the node in A, so that the
next possible smaller nodes in B, with values < 'match_value' are not 
targeted. */
static void set_target_for_a(t_stack *a, t_stack *b) // might be set to static
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
		/* printf("Node: %d\n", node_a->value);
		if (node_a->target_node != NULL)
        	printf("Target node: %d\n", node_a->target_node->value);
		else
        	printf("Target node: NULL\n"); */
		node_a = node_a->next;
	}
}

static void	set_target_for_b(t_stack *b, t_stack *a)
{
	t_node	*node_b;
	t_node	*node_a;
	t_node	*target_node;
	long	match_value;

	node_b = b->top;
	node_a = a->top;
	match_value = LONG_MAX;
	while (node_a)
	{
		if(node_b->value < node_a->value && node_a->value < match_value)
		{
			match_value = node_a->value;
			target_node = node_a;
		}
		node_a = node_a->next;
	}
	if (match_value == LONG_MAX)
		node_b->target_node = find_min(a);
	else
		node_b->target_node = target_node;
}

static void	push_cost_analisys(t_stack *stack, t_stack *target_stack)
{
	t_node	*current;
	int		len_a;
	int		len_b;

	current = stack->top;
	len_a = stack_len(stack);
	len_b = stack_len(target_stack);
	while (current)
	{
		current->push_price = current->index;
		if (!current->above_median)
			current->push_price = len_a - current->index;
		if (current->target_node->above_median == true)
			current->push_price += current->target_node->index;
		else
			current->push_price += len_b - current->target_node->index;
		current = current->next;
	}
}