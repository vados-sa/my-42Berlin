#include <unistd.h>

int	main(int ac, char *av[])
{
	int	i;
	int	x;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				x = av[1][i] - 64;
				while (x > 0)
				{
					write(1, &av[1][i], 1);
					x--;
				}
			}
			else if (av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				x = av[1][i] - 96;
				while (x > 0)
				{
					write(1, &av[1][i], 1);
					x--;
				}
			}
			else
				write(1, &av[1][i], 1);
			i++;
		}
		
	}
	write(1, "\n", 1);
}

/*I could divide my funtion in 3, to fit in the 25 lines limit.
The main that does the ac check and prints the new line at the end, and calls
a function that repeats the alphabet letters. Inside this second funtion,
I can call a function to write the characters*/