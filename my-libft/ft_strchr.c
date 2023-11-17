#include <stdio.h>

char	*ft_strchr(const char *s, int c);
int	ft_strlen(const char *str);

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);	
}

char *ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (char*)(s + ft_strlen(s));
	else
	{
		while (s[i] != '\0')
		{
			if (s[i] == c)
				return (char*)(s + i);
			else
				i++;
		}
	}
	return (0);
}

int	main(void)
{
	char	str[] = "sabao cracra";
	char	c = 'c';
	printf("%s\n", ft_strchr(str, c));
	return (0);
}