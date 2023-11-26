#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*substr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
        return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}

int	main(void)
{
	const char	str[] = "abcdefghijklmnopqrstuvwxyz";
	unsigned int	start = 5;
	size_t	len = 26;
	printf ("%s\n", ft_substr(str, start, len));
	free (ft_substr(str, start, len));
	return (0);
}