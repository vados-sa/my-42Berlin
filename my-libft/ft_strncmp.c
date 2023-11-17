#include <stdio.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	char s1[] = "hello";
	char s2[] = "he";
	unsigned int n = 4;
	printf("funtion: %d\nimplement.: %d\n", strncmp(s1, s2, n), ft_strncmp(s1, s2, n));
	return (0);
}