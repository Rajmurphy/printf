#include "main.h"

/**
* print_hex_number - Print an unsigned integer in hexadecimal format
* @n: Unsigned integer to print
* @spec: Format specifier ('x' or 'X')
* Return: Number of characters printed
*/

int print_hex_number(unsigned int n, char spec)
{
	int count = 0;
	int remainder;
	char hex_chars[16] = "0123456789abcdef";

	if (n / 16)
		count += print_hex_number(n / 16, spec);
	remainder = n % 16;

	if (spec == 'X')
		_pchar(hex_chars[remainder] - 32); /* Convert to uppercase*/
	else
		_pchar(hex_chars[remainder]);
	count++;
	return (count);
}
