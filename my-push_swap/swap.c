#include "push_swap.h"

/*Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.*/
void	sa(t_stack *stack_a)
{
	swap(stack_a);
}

/*Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.*/
void	sb(t_stack *stack_b)
{
	swap(stack_b);
}

/*sa and sb at the same time.*/
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;	

	if (!stack || !stack->top || !stack->top->next)
		return ; // checks if there are at least two elements to swap.
	first = stack->top; // first points to the top node.
	second = first->next; // second points to the node immediately after the top.
	first->next = second->next; // first now points to the third node in the stack, or NULL if no third node exists. 
	second->next = first; // sets second to point to node first, that is now second.
	stack->top = second; // updates 'top' pointer of t_stack points to second, making it the top element of the stack.
}
/* 'stack->top' access the top node of the stack.
   'stack->top->next' access the second node. */
