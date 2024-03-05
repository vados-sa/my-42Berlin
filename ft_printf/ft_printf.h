/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:18:02 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/05 16:26:12 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

/*ft_printf.c*/
int			ft_printf(const char *format, ...);

/*utils.c*/
int			ft_putnbr_base(int nbr, char *base);
int			ft_putnbr_base_unsign(unsigned int nbr, char *base);
int			ft_putnbr_hex_base(unsigned long long nbr, char *base);
size_t		ft_strlen(const char *str);

/*printers*/
int			print_char(char c);
int			print_str(char *s);
int			print_pointer(void *ptr);
int			print_sign_dec_int(int number);
int			print_unsign_dec_int(unsigned int number);
int			print_hex_int_low(unsigned int nbr);
int			print_hex_int_upper(unsigned int nbr);

#endif