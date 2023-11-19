#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (needle[0] == '\0')
		return (char*)(haystack + 0);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j < len))
		{
			if (needle[j + 1] == '\0')
				return (char*)(haystack + i);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	char haystack[] = "Testing with an empty needle";
	char needle[] = "";
	size_t len = 28;
	printf("funtion: %s.\nimplement.: %s.\n", strnstr(haystack, needle, len), ft_strnstr(haystack, needle, len));
	return (0);
}