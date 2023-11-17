
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned	i;
	unsigned	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (i < size - 1 && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (i);
}

int	main(void)
{
	char src[] = " S";
	char dest[15] = "Vanessa";
	printf("Size of concatenated str: %zu.\nConcatenated string: %s.\n", ft_strlcat(dest, src, sizeof(dest)), dest);
	return (0);
}