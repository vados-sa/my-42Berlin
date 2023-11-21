#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		tmp[n];

	i = 0;
	d = dest;
	s = src;
	while (i < n)
	{
		tmp[i] = s[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		d[i] = tmp[i];
		i++;
	}
	return (dest);
}

int	main(void)
{
	char source[] = "Copycat";
	char destination[20];
	char dest[20];

	destination[5] = '\0';
	dest[5] = '\0';

	printf("Destination: %s\n", (char *)memmove(source + 2, source, 3));
	printf("Dest.: %s\n", (char *)ft_memmove(source + 2, source, 3));
	return 0;
}