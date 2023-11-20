/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:08:35 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/20 13:11:10 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h> */

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != '\0')
		ptr++;
	while (ptr >= s)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr--;
	}
	return (0);
}
/* 
int	main(void)
{
	char	str[] = "sabao cracra";
	char	c = 'c';
	printf("%s\n", ft_strrchr(str, c));
	return (0);
} */