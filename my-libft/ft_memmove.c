#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;
	
	i = 0;
	if (dest == (void *)0 && src == (void *)0)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (dest > src)
	{
		d += n - 1;
		s += n - 1;
		while (n > 0)
		{
			d[n] = s[n];
			n--;
		}
//still figuring out this part.		
	}
	else
	{
		while ((n > 0))
		{
			*d++ = *s++;
			n--;
		}
	}
	
	return (dest);
}

int	main(void)
{
	char source[] = "Copycat";
	char destination[7];
	char dest[7];

	printf("Destination: %s\n", (char *)memmove(destination, source, 7));
	printf("Dest.: %s\n", (char *)ft_memmove(dest, source, 7));
	return 0;
}