#include "ft_printf.h"

int	print_hex_int_upper(unsigned int nbr)
{
	return (ft_putnbr_hex_base(nbr, 16, "0123456789ABCDEF"));
}

int main() {
    // Test case with a regular positive number
    unsigned int num1 = 255;
    print_hex_int_upper(num1);
    printf("\n");
	printf("%X", num1);
    printf("\n");

    // Test case with zero
    unsigned int num2 = 0;
    print_hex_int_upper(num2);
    printf("\n");
	printf("%X", num2);
    printf("\n");

    // Test case with a large positive number
    unsigned int num3 = 4294967295; // Maximum unsigned int value
    print_hex_int_upper(num3);
    printf("\n");
	printf("%X", num3);
    printf("\n");

    // Test case with various positive numbers
    unsigned int num4 = 16;
    print_hex_int_upper(num4);
    printf("\n");
	printf("%X", num4);
    printf("\n");

    unsigned int num5 = 255;
    print_hex_int_upper(num5);
    printf("\n");
	printf("%X", num5);
    printf("\n");

    unsigned int num6 = 4095;
    print_hex_int_upper(num6);
    printf("\n");
	printf("%X", num6);
    printf("\n");

    unsigned int num7 = 65535;
    print_hex_int_upper(num7);
    printf("\n");
	printf("%X", num7);
    printf("\n");

    // Test case with a hexadecimal base
    unsigned int num8 = 0x1A3;
    print_hex_int_upper(num8);
    printf("\n");
	printf("%X", num8);
    printf("\n");

    return 0;
}