int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* #include <stdio.h>
int	main(void)
{
	char *str = "I wonder how many characters there is here";

	printf("%i", ft_strlen(str));
	return (0);
} */