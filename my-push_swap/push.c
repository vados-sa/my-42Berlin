#include "push_swap.h"

/* Push A. */
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push_from_to(stack_b, stack_a, "pa\n");
}

/* Push B. */
void	pb(t_stack *stack_b, t_stack *stack_a)
{
	push_from_to(stack_a, stack_b, "pb\n");
}

/*Take the first element at the top of source(b) stack and put it at the
top of destination(a) stack. Do nothing if the src stack is empty*/
void	push_from_to(t_stack *src_stack, t_stack *dest_stack, const char *opr)
{
	t_node	*top_elem;

	if (!src_stack || !src_stack->top) // Check if src_stack is empty
		return ;
	top_elem = pop(src_stack); // Remove the top element from the source stack
	push(dest_stack, top_elem); // Add it to the top of the destination stack
	if (opr)
		write(1, opr, ft_strlen(opr)); // Output the operation name
}

/* Removes the first element of the stack. */
t_node	*pop(t_stack *stack)
{
	t_node	*first;

	if (!stack || !stack->top)
		return (NULL);
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	return (first);
}

/* Adds a new element to the top of the stack. */
void	push(t_stack *stack, t_node *element)
{
	if(!stack || !element)
		return ;
	element->next = stack->top; // Element points to the current top
	stack->top = element; // Element is now the new top.
}
