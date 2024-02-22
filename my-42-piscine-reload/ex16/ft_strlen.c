#include <stdio.h>

int     ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
        i++;
    return(i);
}

int     main()
{
    char str[] = "Chega de mansinho, mandando todo esse beat, toda bonequinha Hello Kitty...";
    printf("Strings's lenght: %d.\n", ft_strlen(&str[0]));
    return 0;
}