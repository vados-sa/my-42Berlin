#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = 0;
	b = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack(&a, av + 1, ac == 2);
	printf("Stack was successfully initialized\n");
	printf("Sorted stack is %s\n", !stack_sorted(a) ? "not sorted" : "sorted");
	/*if (!stack_sorted(a)) // if it's not sorted
	{
		if (stack_len(a) <= 5)
			small_sort(a, b);
		else
			big_sort(a, b);
	}*/
	free_stack(&a);
	return (0);
}
