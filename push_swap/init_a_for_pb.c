#include "push_swap.h"

/* void printNode(t_node *node) {
    printf("Value: %d\n", node->value);
    printf("Index: %d\n", node->index);
    printf("Push price: %d\n", node->push_price);
    printf("Above median: %s\n", node->above_median ? "true" : "false");
    printf("Cheapest: %s\n", node->cheapest ? "true" : "false");
    // For target_node, you can print its value if it's not NULL
    if (node->target_node != NULL) {
        printf("Target node value: %d\n", node->target_node->value);
    } else {
        printf("Target node: NULL\n");
    }
} */

void	init_nodes_a(t_stack **a, t_stack **b)
{
	find_index(*a);
	find_index(*b);
	set_target_for_a(*a, *b);
	push_cost_analisys_a(*a, *b);
	set_cheapest(*a);
}

/*I might have to delete my t_stack stucture and only work with node structure
or current_b = c_b*/
void set_target_for_a(t_stack *a, t_stack *b) // might be set to static
{
	t_node	*current_a;
	t_node	*c_b;
	t_node	*target_node;
	long	match_index;

	current_a = a->top;
	while (current_a)
	{
		c_b = b->top;
		match_index = LONG_MIN;
		while (c_b)
		{
			if (current_a->value > c_b->value && c_b->value > match_index)
			{
				match_index = c_b->value;
				target_node = c_b;
			}
			c_b = c_b->next;
		}
		if (match_index == LONG_MIN)
			current_a->target_node = find_max(b);
		else
			current_a->target_node = target_node;
		current_a = current_a->next;
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