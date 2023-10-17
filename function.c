#include "main.h"

/**
 * Function declarations
 */
unsigned long int convert_size_unsgnd(unsigned long int num, int size);
int write_unsignd(int fd, int i, char buffer[], int flags, int width, int precision, int size);

/**
 * Print a number in the specified base
 */
int print_base(va_list types, char map_to[], char buffer[],
              int flags, char flag_ch, int base, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;

    UNUSED(width);

    num = convert_size_unsgnd(num, size);

    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num > 0)
    {
        buffer[i--] = map_to[num % base];
        num /= base;
    }

    if (flags & F_HASH && init_num != 0)
    {
        buffer[i--] = flag_ch;
        buffer[i--] = '0';
    }

    i++;

    return write_unsgnd(0, i, buffer, flags, width, precision, size);
}

/**
 * Print an unsigned number
 */
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    return print_base(types, "0123456789", buffer, flags, 'x', 10, width, precision, size);
}

/**
 * Print an octal number
 */
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    return print_base(types, "01234567", buffer, flags, '0', 8, width, precision, size);
}

/**
 * Print a lowercase hexadecimal number
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    return print_base(types, "0123456789abcdef", buffer, flags, 'x', 16, width, precision, size);
}

/**
 * Print an uppercase hexadecimal number
 */
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size)
{
    return print_base(types, "0123456789ABCDEF", buffer, flags, 'X', 16, width, precision, size);
}
