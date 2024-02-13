#include "push_swap.h"

void	create_stack(t_stack *stack, char **args);

void	create_stack(t_stack *stack, char **args)
{
	int	i;

	/*do atoi at some point*/

	i = 0;
	while (args[i])
	{
		if (!ft_isdigit(args[i]))
		{
			write(1, "Error\n", 6);
		}
	}
	/*iterate through the arguments checking if they are valid.
	error handling: if any element is not a number, print error 
	message, free the previous arguments and quit.
	if it's valid, add to stack, and free it.*/
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
		av = ft_split(av[1], ' '); // ft_split allocates memory!
	create_stack(&a, av);
	/*check if stack is sorted. if not, sort*/
	return (0);
}

/*error handling:
write(2, "Error\n", 6);*/
