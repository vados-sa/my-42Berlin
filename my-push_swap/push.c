#include "push_swap.h"

static void	from_to(t_stack *src_stack, t_stack *dest_stack, const char *opr);
static t_node	*pop_op(t_stack *stack);
static void	push_op(t_stack *stack, t_node *element);

/* Push A. */
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	from_to(stack_b, stack_a, "pa\n");
}

/* Push B. */
void	pb(t_stack *stack_b, t_stack *stack_a)
{
	from_to(stack_a, stack_b, "pb\n");
}

/*Take the first element at the top of source(b) stack and put it at the
top of destination(a) stack. Do nothing if the src stack is empty*/
static void	from_to(t_stack *src_stack, t_stack *dest_stack, const char *opr)
{
	t_node	*top_elem;

	if (!src_stack || !src_stack->top) // Check if src_stack is empty
		return ;
	top_elem = pop_op(src_stack); // Remove the top element from the source stack
	push_op(dest_stack, top_elem); // Add it to the top of the destination stack
	if (opr)
		write(1, opr, ft_strlen(opr)); // Output the operation name
}

/* Removes the first element of the stack. */
static t_node	*pop_op(t_stack *stack)
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
static void	push_op(t_stack *stack, t_node *element)
{
	if(!stack || !element)
		return ;
	element->next = stack->top; // Element points to the current top
	stack->top = element; // Element is now the new top.
}
