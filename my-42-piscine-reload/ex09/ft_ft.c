#include <stdio.h>

void    ft_ft(int *nbr)
{
    *nbr = 42;
}

int     main()
{
    int number;
    number = 0;
    printf("%d\n", number);
    ft_ft(&number);
    printf("%d", number);
    return 0;
}