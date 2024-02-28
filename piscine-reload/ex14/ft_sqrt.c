//It might not be better than my piscine ft_sqrt.
#include <stdio.h>

int ft_sqrt(int nb)
{
    int     i;
    
    if (nb >= 0)
    {
        i = 0;
        while (i <= nb)
        {
            if (nb == i * i)
                return (i);
            i++;
        }
    }
    return (0);
}

int     main()
{
    printf("The square root is: %d.\n", ft_sqrt(2147395601));
    return 0;
}