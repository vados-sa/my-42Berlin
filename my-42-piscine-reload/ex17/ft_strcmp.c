#include <string.h>
#include <stdio.h>

int     ft_strcmp(char *s1, char *s2);

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

int     main()
{
    char    s1[] = "gaTo";
    char    s2[] = "gaTolho";
    printf("%d\n", strcmp(&s1[0], &s2[0]));
    printf("%d\n", ft_strcmp(&s1[0], &s2[0]));
    return 0;
}
