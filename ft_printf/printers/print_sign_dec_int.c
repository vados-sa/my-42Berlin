/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sign_dec_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:18:58 by vados-sa          #+#    #+#             */
/*   Updated: 2023/12/20 12:35:08 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_sign_dec_int(int number)
{
	long int	n;

	n = number;
	return (ft_putnbr_base(n, "0123456789"));
}

/* int	main()
{

	int num1 = 123456;
	print_sign_dec_int(num1);
	printf("\n");
	printf("%u\n", num1);

	int num2 = -42;
	print_sign_dec_int(num2);
	printf("\n");
	printf("%u\n", num2);

	int num3 = -987654321;
	print_sign_dec_int(num3);
	printf("\n");
	printf("%u\n", num3);

	//octal
	int num4 = 042;
	print_sign_dec_int(num4);
	printf("\n");
	printf("%u\n", num4);

	//haxadecimal
	int num5 = 0x1A3;
	print_sign_dec_int(num5);
	printf("\n");
	printf("%u\n", num5);
	
	return (0);
} */