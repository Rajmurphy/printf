#include "main.h"

/**
 * print_number_base - Print an unsigned number in the specified base.
 *
 * @types: List of arguments
 * @buffer: Buffer array to handle the print
 * @flags: Calculates active flags
 * @base: The base for number representation (e.g., 8 for octal, 16 for hexadecimal)
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * @map_to: Array of values to map the number to (e.g., "0123456789ABCDEF" for hex)
 * @flag_ch: The character for flags (e.g., 'x' for hex)
 *
 * Returns: Number of characters printed.
 */
<<<<<<< HEAD
unsigned long int convert_size_unsgnd(unsigned long int num, int size);
int write_unsignd(int fd, int i, char buffer[], int flags, int width, int precision, int size);

/**
 * Print a number in the specified base
 */
int print_base(va_list types, char map_to[], char buffer[],
              int flags, char flag_ch, int base, int width, int precision, int size)
{
=======
int print_number_base(va_list types, char buffer[], int flags, int width, int precision, int size, int base, const char *map_to, char flag_ch) {
>>>>>>> 19066a78d043867920c870b215e61e5aece6f741
    int i = BUFF_SIZE - 2;
    unsigned long int num = va_arg(types, unsigned long int);
    unsigned long int init_num = num;
    unsigned long int convert_size_unsgnd(unsigned long int num, int size);


    UNUSED(width);

    num = convert_size_unsgnd(num, size);

    if (num == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';

    while (num > 0) {
        buffer[i--] = map_to[num % base];
        num /= base;
    }

    if (flags & F_HASH && init_num != 0) {
        buffer[i--] = flag_ch;
        buffer[i--] = '0';
    }

    i++;

    return write_unsgnd(0, i, buffer, flags, width, precision, size);
}

/**
 * print_unsigned - Print an unsigned number in decimal.
 */
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size) {
    return print_number_base(types, buffer, flags, width, precision, size, 10, "0123456789", 'x');
}

/**
 * print_octal - Print an unsigned number in octal notation.
 */
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size) {
    return print_number_base(types, buffer, flags, width, precision, size, 8, "01234567", '0');
}

/**
 * print_hexadecimal - Print an unsigned number in lowercase hexadecimal.
 */
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size) {
    return print_number_base(types, buffer, flags, width, precision, size, 16, "0123456789abcdef", 'x');
}

/**
 * print_hexa_upper - Print an unsigned number in uppercase hexadecimal.
 */
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size) {
    return print_number_base(types, buffer, flags, width, precision, size, 16, "0123456789ABCDEF", 'X');
}
