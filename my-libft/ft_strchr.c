/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:41:46 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/20 12:53:46 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

char	*ft_strchr(const char *s, int c);

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	if ((unsigned char)c == '\0')
		return (ptr);
	else
	{
		while (*ptr != '\0')
		{
			if (*ptr == (unsigned char)c)
				return (ptr);
			ptr++;
		}
	}
	return (0);
}

/* int	main(void)
{
	char	str[] = "sabao cracra";
	char	c = 'c';
	printf("%s\n", ft_strchr(str, c));
	return (0);
} */