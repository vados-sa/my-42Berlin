#include "push_swap.h"

t_stack	*init_stack(void);
int		valid_input(char **args);
void	error_exit(void);
void	fill_stack(t_stack *stack, char **args);

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	return (stack);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	fill_stack(t_stack *stack, char **args)
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
	char	**numbers;

	a = init_stack();
	b = init_stack();
	numbers = av;
	if (ac == 1 || (ac == 2 && !av[1][0])) // initial check for empty or no input; 
		return (1);
	else if (ac == 2)
		numbers = ft_split(av[1], ' '); // ft_split allocates memory!
	valid_input(numbers); // check if the input is valid
	fill_stack(&a, av);
	/*check if stack is sorted. if not, sort*/
	return (0);
}
