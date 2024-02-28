/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:15:47 by vados-sa          #+#    #+#             */
/*   Updated: 2023/12/20 12:35:04 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/* uintptr_t is an unsigned integer type that is guaranteed to be able to hold
the value of a pointer, without loss of information. */
int	print_pointer(void *ptr)
{
	int							i;
	unsigned long long			ptr_value;

	i = 0;
	if (ptr == 0)
		i += print_str("(nil)");
	else
	{
		ptr_value = (unsigned long long)ptr;
		i += print_str("0x");
		if (i < 0)
			return (-1);
		i += ft_putnbr_hex_base(ptr_value, "0123456789abcdef");
	}
	if (i < 0)
		return (-1);
	return (i);
}

/* int main(void)
{
	int value = 42;

	int *validPtr = &value;
	printf("Valid Pointer: ");
	print_pointer(validPtr);
	printf("\n");
	printf("%p\n", validPtr);

	int *nullPtr = 0;
	printf("Null Pointer: ");
	print_pointer(nullPtr);
	printf("\n");
	printf("%p\n", nullPtr);

	return 0;
} */