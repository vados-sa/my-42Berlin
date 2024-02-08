#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;	

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return ; // checks if there are at least two elements to swap.
	first = stack->top; // first points to the top node.
	second = first->next; // second points to the node immediately after the top.
	first->next = second->next; // first now points to the third node in the stack, or NULL if no third node exists. 
	second->next = first; // sets second to point to node first, that is now second.
	stack->top = second; // updates 'top' pointer of t_stack points to second, making it the top element of the stack.
}

/* 'stack->top' access the top node of the stack.
   'stack->top->next' access the second node. */

void	sa(t_stack *stack_a)
{
	swap(stack_a);
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
