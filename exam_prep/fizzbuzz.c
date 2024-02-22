#include <unistd.h>

int	main(void)
{
	int	i;
	int	dec = 0;
	int	uni = 0;

	i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if((i % 3 == 0))
			write(1, "fizz", 4);
		else if((i % 5 == 0))
			write(1, "buzz", 4);
		else if (i > 0 && i <= 9)
		{
			uni = i + 48;
			write (1, &uni, 1);
		}
		else
		{
			dec = i / 10;
			uni = i % 10;
			dec += 48;
			uni += 48;
			write(1, &dec, 1);
			write(1, &uni, 1);
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
/*In order to respect the 25 lines limit, the two last else conditions
could be added into a function that writes the numbers. In this fuction,
an array of 10 characters, 0 - 9, is created. Using recursion, the numbers
bigger than 9 can be written, also using division and module*/