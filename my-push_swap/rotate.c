#include "push_swap.h"

/* Shift up all elements of stack a by 1.
The first element becomes the last one. */
void    rotate(t_stack *stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !stack->top || !stack->top->next) //check if there's at least 2 elements.
		return ;
	first = stack->top; // save the current top element; 
	stack->top = first->next; // update the top of the stack to the second element;
	last = stack->top; // start looking for the last element from the new top;
	while (last->next)
		last = last->next; // traverse to find the last element;
	last->next = first; // append the first element to the end of the list;
	first->next = NULL; // now, detach the first element and make it the last.
}

/* Rotate A. */
void    ra(t_stack *stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

/* Rotate B. */
void    rb(t_stack *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

/* ra and rb at the same time. */
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
