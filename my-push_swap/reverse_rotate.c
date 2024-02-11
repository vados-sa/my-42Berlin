#include "push_swap.h"

/*Shift down all elements of stack a by 1.
The last element becomes the first one.*/
void    rra(t_stack *stack_a)
{
	t_list	*last;
	t_list	*prev_to_last;

	if (!stack_a || !stack_a->top || !stack_a->top->next) //check if there's at least 2 elements.
		return ;
	last = stack_a->top;
	prev_to_last = NULL;
	while (last->next) // traverse to find the last and the second to last elements;
	{
		prev_to_last = last; // keep track of the second to last;
		last = last->next; // move to the next node;
	}
	if (prev_to_last)
	{
		prev_to_last->next = NULL; // disconnects the last element from the second to last;
		last->next = stack_a->top; // point the last element to the current top;
		stack_a->top = last; // update the top of the stack to the last element;
	}
}

/*Shift down all elements of stack b by 1.
The last element becomes the first one.*/
void    rrb(t_stack *stack_b)
{
	t_list	*last;
	t_list	*prev_to_last;

	if (!stack_b || !stack_b->top || !stack_b->top->next) //check if there's at least 2 elements.
		return ;
	last = stack_b->top;
	prev_to_last = NULL;
	while (last->next) // traverse to find the last and the second to last elements;
	{
		prev_to_last = last; // keep track of the second to last;
		last = last->next; // move to the next node;
	}
	if (prev_to_last)
	{
		prev_to_last->next = NULL; // disconnects the last element from the second to last;
		last->next = stack_b->top; // point the last element to the current top;
		stack_b->top = last; // update the top of the stack to the last element;
	}
}
/*rra and rrb at the same time.*/
void    rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}