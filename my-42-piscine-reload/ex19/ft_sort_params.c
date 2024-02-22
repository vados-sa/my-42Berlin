void    ft_putchar(char c);
int     ft_strcmp(char *s1, char *s2);
void    ft_swap(char **a, char **b);
void ft_print_parameters(int ac, char *av[]);

#include <unistd.h>
void    ft_putchar(char c)
{
    write(1, &c, 1);
}


int ft_strcmp(char *s1, char *s2)
{
    int     i;
    i = 0;
    while (s1[i] != '\0' || s2[i] != '\0')
    {
        if (s1[i] == s2[i])
			i++;
		if (s1[i] < s2[i] || s1[i] > s2[i])
			return (s1[i] - s2[i]);
    }
    return 0;
}

void    ft_swap(char **a, char **b)
{
    char *tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void ft_print_parameters(int ac, char *av[])
{
    int i;
    int j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        while (av[i][j] != '\0')
        {
            ft_putchar(av[i][j]);
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

int     main(int ac, char *av[])
{
    int i;
    int cmp;
    
    i = 1;
    while (i < ac - 1)
    {
        cmp = ft_strcmp(av[i], av[i + 1]);
        if (cmp > 0)
        {
            ft_swap(&av[i], &av[i + 1]);
            i = 1;
        }
        else
            i++;     
    }
    ft_print_parameters(ac, av);
    return 0;
}