#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	valid_input(char **args) // put it on a check.c fie;
{
	int	i;
	int	j;

	i = 0;
	while (args[i]) //check if they are intergers
	{
        j = 0;
        while (args[i][j])
        {
			if (j == 0 && (args[i][j] == '-' || args[i][j] == '+')) // Allow a minus sign at the start
        	{
        		// Check the next character to ensure it's a digit
        		if (!args[i][j + 1] || !ft_isdigit(args[i][j + 1]))
            		error_exit(); // Not a valid number
				j++;
			}
            else
			{
				if (!ft_isdigit(args[i][j]))
        			error_exit();
    			j++;  
			}	
        }
        i++;
	}
	i = 0;
	while (args[i]) //check if there are no duplicates
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_strncmp(args[i], args[j], 11) == 0)
				error_exit();
			else
				j++;
		}
		i++;
	}
	return (i);
}

int	main(int ac, char *av[])
{
	/* char	**numbers;

	numbers = av; */
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	/* else if (ac == 2)
		numbers = ft_split(av[1], ' '); */
	if(ac > 1 && valid_input(av + 1))
        printf("Input is valid\n");
    //free (numbers);
    return(0);
}
