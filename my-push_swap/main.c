#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = 0;
	b = 0;
	if (ac == 1 || (ac == 2 && !av[1][0])) // initial check for empty or no input; 
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' '); // ft_split allocates memory!
	//init_stack(&a, av + 1, ac == 2); //initializes the stack and check if the input is valid;
	/*check if stack is sorted. if not, sort*/
	return (0);
}