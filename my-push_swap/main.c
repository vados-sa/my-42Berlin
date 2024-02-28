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
	print_stack(a, 'A'); // remember to take this out
	printf("stack length: %d\n", stack_len(a)); // remember to take this out
	printf("Sorted stack is %s\n", !stack_sorted(a) ? "not sorted" : "sorted"); // remember to take this out
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(a);
		else if (stack_len(a) == 3)
			sort_three(a);
		else
			big_sort(&a, &b);
		print_stack(a, 'A'); // remember to take this out
	}
	free_stack(&a);
	return (0);
}
