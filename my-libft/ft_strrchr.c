#include <stdio.h>

char	*ft_strrchr(const char *s, int c);
int	ft_strlen(const char *str);

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);	
}

char *ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return (char*)(s + i);
		else
			i--;
	}
	return (0);
}

int	main(void)
{
	char	str[] = "sabao cracra";
	char	c = 'c';
	printf("%s\n", ft_strrchr(str, c));
	return (0);
}