#include "push_swap.h"

void	print_stack(t_stack *stack, char stack_name) // remember to take this out
{
    t_node *current;

	current = stack->top;
    printf("Stack contents %c:\n", stack_name);
    while (current)
	{
        printf("%d\n", current->value);
        current = current->next;
    }
}
//print_stack(a, 'A');
/* void printNode(t_node *node) {
    printf("Value: %d\n", node->value);
    printf("Index: %d\n", node->index);
    printf("Push price: %d\n", node->push_price);
    printf("Above median: %s\n", node->above_median ? "true" : "false");
    printf("Cheapest: %s\n", node->cheapest ? "true" : "false");
    // For target_node, you can print its value if it's not NULL
    if (node->target_node != NULL) {
        printf("Target node value: %d\n", node->target_node->value);
    } else {
        printf("Target node: NULL\n");
    }
} */

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack(&a, av + 1, ac == 2);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(a);
		else if (stack_len(a) == 3)
			sort_three(a);
		else
			big_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
