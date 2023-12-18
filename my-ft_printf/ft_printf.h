/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanessasantos <vanessasantos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:18:02 by vados-sa          #+#    #+#             */
/*   Updated: 2023/12/18 14:57:08 by vanessasant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	print_char(char c);
int	print_str(char *s);
int    print_pointer(void *ptr);
int	print_sign_dec_int(int number);
size_t	ft_strlen(const char *str);
int ft_putnbr_base(int nbr, char *base);
int	print_unsign_dec_int(unsigned int number);
int ft_putnbr_base_unsign(unsigned int nbr, char *base);
int	print_hex_int_low(unsigned int nbr);
int	print_hex_int_upper(unsigned int nbr);
int ft_putnbr_hex_base(unsigned int nbr, unsigned int baseLen, char *base);

#endif