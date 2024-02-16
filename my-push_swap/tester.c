#include "push_swap.h"

int	valid_input(char **args);
int	is_integer(char **args);
int	has_duplicates(char **args);
void	error_exit(void);

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_integer(char **args)
{
	long long num;
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		if (!(ft_isdigit(args[i][0]) || args[i][0] == '-' || args[i][0] == '+')
			&& args[i][1] != '\0')
            return (1);
        num = ft_atoll(args[i]);
        if (num < -2147483648 || num > 2147483647)
            return (1);
		j = (args[i][0] == '-' || args[i][0] == '+') ? 1 : 0; // ternary operators are forbiden!!!!
        while (args[i][j])
        {
			if (!ft_isdigit(args[i][j]))
        			return (1);
    			j++;  
		}	
        i++;
	}
	return (0);
}
int	has_duplicates(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	valid_input(char **args)
{
	// atoll before checking
	// go through each number, do the check and add them to the stack.

	if (is_integer(args) || has_duplicates(args))
		error_exit();
	return (1);
}

int	main(int ac, char *av[])
{
	char	**numbers;
	int		i;

	//numbers = av;
	i = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		numbers = ft_split(av[1], ' ');
		if (valid_input(numbers))
            printf("Input is valid\n");
		
	}
	if(ac > 1 && valid_input(av + 1)) // av + 1 to skip the program's name
        printf("Input is valid\n");
    return(0);
}
