#include <stdio.h>

int     ft_iterative_factorial(int nb)
{
    int     i;
    int     result;

    result = 1;
    if (nb >= 0 && nb <= 15)
    {
        i = 1;
        while(i <= nb)
        {
            result = i * result;
            i++;    
        }    
    }
    else
        return 0;
    return (result);
}

int     main()
{
    printf("The factorial is: %d\n", ft_iterative_factorial(17));
    return 0;
}