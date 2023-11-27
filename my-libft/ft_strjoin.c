#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t  i;
    size_t  j;
    char    *join;

    join = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!join)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
        join[j++] = s1[i++];
    i = 0;
    while (s2[i])
        join[j++] = s2[i++];
    join[j] = '\0';
    return (join);    
}

int main(void)
{
    char str1[] = "Vanessa ";
    char str2[] = "Santos";
    char *result = ft_strjoin(str1, str2);
    if (result)
    {
        printf("%s\n", result);
        free(result);
    }
    return (0);
}