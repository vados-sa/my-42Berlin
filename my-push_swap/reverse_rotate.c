#include "push_swap.h"

/*Shift down all elements of the stack by 1.
The last element becomes the first one.*/
void    reverse_rotate(t_stack *stack)
{
	t_list	*last;
	t_list	*prev_to_last;

	if (!stack || !stack->top || !stack->top->next) //check if there's at least 2 elements.
		return ;
	last = stack->top;
	prev_to_last = NULL;
	while (last->next) // traverse to find the last and the second to last elements;
	{
		prev_to_last = last; // keep track of the second to last;
		last = last->next; // move to the next node;
	}
	if (prev_to_last)
	{
		prev_to_last->next = NULL; // disconnects the last element from the second to last;
		last->next = stack->top; // point the last element to the current top;
		stack->top = last; // update the top of the stack to the last element;
	}
}

/* Reverse rotate A. */
void    rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

/* Reverse rotate B. */
void    rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

/* rra and rrb at the same time. */
void    rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}