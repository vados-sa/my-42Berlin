#include <unistd.h>

int	main(int ac, char *av[])
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] == ' ' || av[1][i] == '\t')
				i++;
			else
			{
				write (1, &av[1][i], 1);
				if (av[1][i + 1] == ' ' || av[1][i + 1] == '\t')
					break;
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}

/*I could also create 2 while loops.
the first one to iterate through spaces and tabs, and the second one to 
write the characters while I don't hit the '\0' or it is not spaces nor tabs.*/
