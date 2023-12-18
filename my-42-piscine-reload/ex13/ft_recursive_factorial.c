#include <stdio.h>

int     ft_recursive_factorial(int nb)
{
    if (nb == 0)
        return (1);
    if (nb > 0 && nb <= 15)
        return (nb * ft_recursive_factorial(nb - 1));
    else
        return (0);
}

int     main()
{
    printf("The factorial is: %d\n", ft_recursive_factorial(-10));
    return 0;
}