#include "push_swap.h"

void    ra(t_stack *stack_a)
{
	t_list	*first;
	t_list	*last;

	if (!stack_a || !stack_a->top || !stack_a->top->next) //check if there's at least 2 elements.
		return ;
	first = stack_a->top; // save the current top element; 
	stack_a->top = first->next; // update the top of the stack to the second element;
	last = stack_a->top; // start looking for the last element from the new top;
	while (last->next)
		last = last->next; // traverse to find the last element;
	last->next = first; // append the first element to the end of the list;
	first->next = NULL; // now, detach the first element and make it the last.
}

void    rb(t_stack *stack_b)
{
	t_list	*first;
	t_list	*last;

	if (!stack_b || !stack_b->top || !stack_b->top->next) //check if there's at least 2 elements.
		return ;
	first = stack_b->top; // save the current top element; 
	stack_b->top = first->next; // update the top of the stack to the second element;
	last = stack_b->top; //start looking for the last element from the new top;
	while (last->next)
		last = last->next; // traverse to find the last element;
	last->next = first; // append the first element to the end of the list;
	first->next = NULL; // now, detach the first element and make it the last.
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
