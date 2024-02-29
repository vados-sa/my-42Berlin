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
	*b = malloc(sizeof(t_stack));
	if (!*b)
		return ;
	if (a_len-- > 3 && !stack_sorted(*a))
		pb(*b, *a);
	//print_stack(*b);
	if (a_len-- > 3 && !stack_sorted(*a))
		pb(*b, *a);
	print_stack(*b, 'B');
	while (a_len-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(a, b);
		push_cheapest_a(a, b);
	}
	print_stack(*b, 'B');
	print_stack(*a, 'A');
	sort_three(*a);
	print_stack(*a, 'A');
	init_nodes_b(b, a);
	/* while(*b)
	{
		init_nodes_b(b, a);
		push_cheapest_b(a, b);
	}
	print_stack(*b, 'B');
	free_stack(b);
	find_index(*a); // refresh current position of stack 'a'
	smallest_on_top(*a); // ensure smallest number is on top */
}
