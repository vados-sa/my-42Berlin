void    ft_putchar(char c);
void ft_putstr(char *str);

#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
    
}

int     main()
{
    char str[] = "Hello World!";
    ft_putstr(&str[0]);
}
