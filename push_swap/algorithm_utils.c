#include "push_swap.h"

/*Set the node's current position in the stack, 
and sets the median boolean data to true or false.*/
void	find_index(t_stack *stack)
{
	int		i;
	int		median;
	t_node	*current;

	i = 0;
	if (!stack || !stack->top)
 		return ;
	median = stack_len(stack) / 2;
	current = stack->top;
	while (current)
	{
		current->index = i;
		if (current->index <= median)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
		i++;
	}
}

t_node	*find_max(t_stack *stack)
{
	t_node	*max;
	t_node	*current;

	if (!stack || !stack->top)
 		return NULL;
	max = stack->top;;
	current = stack->top->next;
	while (current)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}

t_node	*find_min(t_stack *stack)
{
	t_node	*min;
	t_node	*current;

	if (!stack || !stack->top)
 		return NULL;
	min = stack->top;
	current = stack->top->next;
	while (current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

void	set_cheapest(t_stack *stack)
{
	t_node		*current;
	t_node		*cheapest_node;
	long		min_push_price = LONG_MAX;		

	if (!stack || !stack->top)
 		return ;
	current = stack->top;
	cheapest_node = NULL;
	while (current)
	{
		if (current->push_price < min_push_price)
		{
			min_push_price = current->push_price;
			cheapest_node = current;
		}
		current = current->next;
	}
	current = stack->top; // Reset all nodes to not cheapest, except the cheapest one
	while (current)
	{
		current->cheapest = false; // Reset every node to not be the cheapest (false)
		current = current->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

t_node	*get_cheapest(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	while (current)
	{
		if (current->cheapest)
			return (current);
		current = current->next;
	}
	return (NULL);
}
