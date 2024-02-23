#include "push_swap.h"

void	sort_3(t_stack *a)
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

void	small_sort(t_stack *a)
{
	int	len;

	len = stack_len(a);
	if (len == 3)
		sort_3(a);
	/*if (len == 4)
		sort_4(a);
	if (len == 5)
		sort_5(a);*/
}