#include "push_swap.h"

void print_stack(t_stack *stack)
{
    t_node *current;

	current = stack->top;
    printf("Stack contents:\n");
    while (current)
	{
        printf("%d\n", current->value);
        current = current->next;
    }
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	//t_stack	*b;

	a = NULL;
	//b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack(&a, av + 1, ac == 2);
	printf("Stack was successfully initialized\n");
	print_stack(a);
	printf("Sorted stack is %s\n", !stack_sorted(a) ? "not sorted" : "sorted");
	printf("stack length: %d\n", stack_len(a));
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(a);
		else if (stack_len(a) > 2 && stack_len(a) <= 5)
			small_sort(a); 
		//else
			//big_sort(a, b);
		print_stack(a);
	}
	free_stack(&a);
	return (0);
}
