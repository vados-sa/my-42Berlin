#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int     main()
{
    int a, b;
    a = 2;
    b = 4;
    printf("%d%d\n", a, b);
    ft_swap(&a, &b);
    printf("%d%d\n", a, b);
    return 0;
}