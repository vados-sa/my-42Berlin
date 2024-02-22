#include "push_swap.h"

/*
middle->value as top->next->value
bottom->value as top->next->next->value
*/
void	sort_3(t_stack *a)
{
	t_node	*top;

	top = a->top;
	if (top->value > top->next->value)
	{
		if (top->next->value > top->next->next->value)
		{
			ra(a);
			sa(a);
		}
		else
		{
			if (top->value > top->next->next->value)
				ra(a);
			else
				sa(a);
		}
	}
	else if (top->value < top->next->value)
	{
		rra(a);
		if (top->value < top->next->next->value)  //segfault on this line !
			sa(a);
	}
} /*5 if statements will need less lines and might not give me segfaults*/

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