/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanessasantos <vanessasantos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:44:37 by vados-sa          #+#    #+#             */
/*   Updated: 2024/01/25 14:02:30 by vanessasant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

size_t	        ft_strlen(const char *str);
void            *ft_memset(void *s, int c, size_t n);
/* static char	 	*set_remaining(char *line); */
char	        *read_line(char *remain, char *buffer, int fd);
char	        *get_next_line(int fd);
char	        *ft_strdup(const char *s1);
char	        *ft_strchr(const char *s, int c);
char	        *ft_substr(char const *s, unsigned int start, size_t len);
char	        *ft_strjoin(char const *s1, char const *s2);

#endif