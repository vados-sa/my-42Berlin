#include "push_swap.h"

void	sort_three(t_stack *a)
{
	t_node	*top;
	t_node	*middle;
	t_node	*bottom;

	top = a->top;
	middle = a->top->next;
	bottom = middle->next;
	if (top->value > middle->value && middle->value > bottom->value)
	{
		ra(a);
		sa(a);
	}
	else if (top->value > middle->value && top->value > bottom->value)
		ra(a);
	else if (top->value > middle->value && top->value < bottom->value)
		sa(a);
	else if (top->value < middle->value && top->value > bottom->value)
		rra(a);
	else if (top->value < middle->value && top->value < bottom->value)
	{
		rra(a);
		sa(a);
	}
}

void	big_sort(t_stack **a, t_stack **b)
{

	int	a_len;

	a_len = stack_len(*a);
	if (a_len-- > 3)
		pb(b, a);
	if (a_len-- > 3 && !stack_sorted(*a))
		pb(b, a);
	while (a_len-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		push_cheapest_a(a, b);
	}
	print_stack(b);
	sort_three(a);
	/*while(*b)
	{
		// initiate nodes from both stacks (focused on b)
		// move all 'b' nodes back to sorted stack 'a'
	}
	//refresh current position of stack 'a'
	// ensure smallest number is on top*/
}
