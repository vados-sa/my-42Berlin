/* int	main(void)
{
	char charValue = 'A';
    const char *stringValue = "Hello, World!";
    int intValue = -42;
    unsigned int uintValue = 12345;
	//function
	int functionCharsPrinted = printf ("Character: %c, String: %s, Integer: %d, Integer: %i, Unsigned Integer: %u, Percent Sign: %%\n", charValue, stringValue, intValue, intValue, uintValue);
	if (functionCharsPrinted < 0)
		printf("ft_printf failed");
	else
		printf("Number of characters printed: %d\n", functionCharsPrinted);
	//implementation
	int	charsPrinted = ft_printf ("Character: %c, String: %s, Integer: %d, Integer: %i, Unsigned Integer: %u, Percent Sign: %%\n", charValue, stringValue, intValue, intValue, uintValue);
	if (charsPrinted < 0)
		printf("ft_printf failed");
	else
		printf("Number of characters printed: %d\n", charsPrinted);
	return (0);
} */


//print_hex_int_low
/* int main(void) 
{
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

    return (0);
} */


//print_hex_int_upper
/* int main() {
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
} */