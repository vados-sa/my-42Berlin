#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*b_top;

	if (!stack_b || !stack_b->top) // check if stack b is empty
		return ;
	b_top = pop(stack_b); // pop from stack_b
	push(stack_a, b_top); //push onto stack_a
}

void	pb(t_stack *stack_b, t_stack *stack_a)
{
	t_list	*a_top;

	if (!stack_a || !stack_a->top) // check if stack a is empty
		return ;
	a_top = pop(stack_a); // pop from stack_b
	push(stack_b, a_top); // push onto stack_a
}
t_list	*pop(t_stack *stack)
{
	t_list	*first;

	if (!stack || !stack->top)
		return (NULL);
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	return (first);
}

void	push(t_stack *stack, t_list *element)
{
	if(!stack || !element)
		return ;
	element->next = stack->top; // Element points to the current top
	stack->top = element; // Element is now the new top.
}