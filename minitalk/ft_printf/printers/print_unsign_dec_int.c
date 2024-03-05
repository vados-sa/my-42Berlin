/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsign_dec_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:19:15 by vados-sa          #+#    #+#             */
/*   Updated: 2023/12/20 12:35:16 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_unsign_dec_int(unsigned int number)
{
	return (ft_putnbr_base_unsign(number, "0123456789"));
}

/* int	main()
{
	// Test case with a regular positive number
	int num1 = 123;
	print_unsign_dec_int(num1);
	printf("\n");
	printf("%u\n", num1);

	// Test case with zero
	int num2 = 0;
	print_unsign_dec_int(num2);
	printf("\n");
	printf("%u\n", num2);

	// Test case with a large positive number
	int num3 = 987654321;
	print_unsign_dec_int(num3);
	printf("\n");
	printf("%u\n", num3);

	// Test case with the maximum unsigned int value
	unsigned int num4 = 4294967295;
	print_unsign_dec_int(num4);
	printf("\n");
	printf("%u\n", num4);

	// Test case with a negative number
	int num5 = -42;
	print_unsign_dec_int(num5);
	printf("\n");
	printf("%u\n", num5);
	
	return (0);
} */