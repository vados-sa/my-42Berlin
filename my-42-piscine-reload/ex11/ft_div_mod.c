#include <stdio.h>

void        ft_div_mod(int a, int b, int *div, int *mod)
{
    if (b != 0)
    {
        *div = a/b;
        *mod = a%b;
    }
}

int     main()
{
    int a, b, div, mod;
    a = -119324;
    b = -10;
    div = 0;
    mod = 0;
    printf("Div is %d and Mod is %d.\n", div, mod);
    ft_div_mod(a, b, &div, &mod);
    printf("Div is now %d and Mod is %d.\n", div, mod);
    return 0;
}