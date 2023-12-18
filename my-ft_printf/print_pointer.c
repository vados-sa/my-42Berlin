#include "ft_printf.h"

int    print_pointer(void *ptr)
{
    int         i;
    unsigned long long   ptrValue; 
    //unsigned long long is an unsigned integer type that is guaranteed to be able to hold
    //the value of a pointer, without loss of information.

    i = 0;
    if (ptr == 0)
        i += print_str("(nil)");
    else
    {
        ptrValue = (unsigned long long)ptr;
        i += print_str("0x");
        if (i < 0)
            return (-1);
        i += ft_putnbr_hex_base(ptrValue, 16, "0123456789abcdef");    
    }
    return (i);
}

int main(void)
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
}