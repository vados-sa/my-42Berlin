#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen(s1);
	while (len > i && ft_strchr(set, s1[len - 1]))
		len--;
	str = malloc((len - i + 1) * sizeof(char));
	if (!str)
		return (NULL);	
	j = 0;
	while (i < len)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);		
}

int main(void)
{
	char s1[] = "\t\t This\nis\ta\ntest \t\t\n\n";
	char set[] = "\t\n";
	char *result = ft_strtrim(s1, set);
	if (result)
	{
		printf("%s", result);
		free(result);
	}
	return (0);
}