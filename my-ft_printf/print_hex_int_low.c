#include "ft_printf.h"

int	print_hex_int_low(unsigned int nbr)
{
	return (ft_putnbr_hex_base(nbr, 16, "0123456789abcdef"));
}

int main() {
    // Test case with a regular positive number
    unsigned int num1 = 255;
    print_hex_int_low(num1);
    printf("\n");
	printf("%x", num1);
    printf("\n");

    // Test case with zero
    unsigned int num2 = 0;
    print_hex_int_low(num2);
    printf("\n");
	printf("%x", num2);
    printf("\n");

    // Test case with a large positive number
    unsigned int num3 = 4294967295; // Maximum unsigned int value
    print_hex_int_low(num3);
    printf("\n");
	printf("%x", num3);
    printf("\n");

    // Test case with various positive numbers
    unsigned int num4 = 16;
    print_hex_int_low(num4);
    printf("\n");
	printf("%x", num4);
    printf("\n");

    unsigned int num5 = 255;
    print_hex_int_low(num5);
    printf("\n");
	printf("%x", num5);
    printf("\n");

    unsigned int num6 = 4095;
    print_hex_int_low(num6);
    printf("\n");
	printf("%x", num6);
    printf("\n");

    unsigned int num7 = 65535;
    print_hex_int_low(num7);
    printf("\n");
	printf("%x", num7);
    printf("\n");

    // Test case with a hexadecimal base
    unsigned int num8 = 0x1A3;
    print_hex_int_low(num8);
    printf("\n");
	printf("%x", num8);
    printf("\n");

    return 0;
}