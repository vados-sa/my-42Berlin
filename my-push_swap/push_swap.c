#include "push_swap.h"

void	error_exit(void);
void	fill_stack(t_stack *stack, char **args);

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}


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
	//init_stack()
	//valid_input(); // check if the input is valid
	//fill_stack(&a, av);
	/*check if stack is sorted. if not, sort*/
	return (0);
}
