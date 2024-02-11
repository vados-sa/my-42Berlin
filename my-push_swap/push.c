#include "push_swap.h"

/*Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty*/
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*b_top;

	if (!stack_b || !stack_b->top) // check if stack b is empty
		return ;
	b_top = pop(stack_b); // pop from stack_b
	push(stack_a, b_top); //push onto stack_a
}

/*Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.*/
void	pb(t_stack *stack_b, t_stack *stack_a)
{
	t_list	*a_top;

	if (!stack_a || !stack_a->top) // check if stack a is empty
		return ;
	a_top = pop(stack_a); // pop from stack_b
	push(stack_b, a_top); // push onto stack_a
}

/* Removes the first element of the stack. */
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

/* Adds a new element to the top of the stack. */
void	push(t_stack *stack, t_list *element)
{
	if(!stack || !element)
		return ;
	element->next = stack->top; // Element points to the current top
	stack->top = element; // Element is now the new top.
}
