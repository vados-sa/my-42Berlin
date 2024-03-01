#include "push_swap.h"

static void	smallest_on_top(t_stack **a)
{
	t_node	*smallest;

	if (!a || !(*a)->top)
 		return ;
	smallest = find_min(*a);
	while ((*a)->top != smallest)
	{
		if (smallest->above_median)
			ra(*a);
		else
			rra(*a);
	}
}

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
	//int	a_len;

	//a_len = stack_len(*a);
	*b = malloc(sizeof(t_stack));
	if (!*b)
		return ;
	(*b)->top = NULL;
	if (stack_len(*a) > 3 && !stack_sorted(*a)) // a_len--
		pb(*b, *a);
	if (stack_len(*a) > 3 && !stack_sorted(*a)) // a_len--
		pb(*b, *a);
	while (stack_len(*a) > 3 && !stack_sorted(*a)) // a_len--
	{
		//print_stack(*a, 'A');
		//printf("Stack lenght: %d\n", stack_len(*a));
		//print_stack(*b, 'B');
		init_nodes_a(a, b);
		push_cheapest_a(a, b);
	}
	//print_stack(*a, 'A');
	//printf("Stack lenght: %d\n", stack_len(*a));
	if (!stack_sorted(*a))
		sort_three(*a);
	//print_stack(*a, 'A');
	while((*b)->top)
	{
		init_nodes_b(b, a);
		push_back_to_a(b, a);
	}
	free_stack(b);
	find_index(*a); // refresh current position of stack 'a'
	smallest_on_top(a); // ensure smallest number is on top
	//print_stack(*a, 'A');
}
