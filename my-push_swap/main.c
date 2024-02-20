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
	printf("Sorted stack is %s\n", is_sorted(a) ? "not sorted" : "sorted");
	/*check if stack is sorted. if not, sort*/
	return (0);
}

/*
ATENTION

so far I'm only freeing when there is an error.
*/
