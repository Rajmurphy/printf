#include "main.h"
#include <stdarg.h>
/**
* _printf - Custom printf implementation
* @format: Format string
* @...: Variable number of arguments
* Return: Number of characters printed
*/

int _printf(const char *format, ...)
{

	va_list args;
	int i, count = 0;
	char spec;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
			count += _pchar(format[i]);
		else if (format[i] == '%' && format[i + 1] != '%')
		{
			i++;
			spec = format[i];

			count += handle_specifier(spec, args);
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			count += _pchar('%');
			i++;
		}
	}
	va_end(args);
	return (count);
}

/**
 * handle_specifier - Handle different format specifiers
 * @spec: Format specifier
 * @args: Argument list
 * Return: Number of characters printed
 */
int handle_specifier(char spec, va_list args)
{
	int j, count = 0;

	if (spec == 'c')
		count += _pchar(va_arg(args, int));
	else if (spec == 's')
	{
		char *str = va_arg(args, char *);

		if (str == NULL)
			str = "(null)";
		for (j = 0; str[j] != '\0'; j++)
			count += _pchar(str[j]);
	}
	if (spec == 'd' || spec == 'i')
		count += print_number(va_arg(args, int));
	else if (spec == 'u')
		count += print_unsigned_number(va_arg(args, unsigned int));
	else if (spec == 'o')
		count += print_octal_number(va_arg(args, unsigned int));
	else if (spec == 'x' || spec == 'X')
		count += print_hex_number(va_arg(args, unsigned int), spec);
	return (count);
}
/**
 * print_unsigned_number - Print an unsigned integer
 * @n: Unsigned integer to print
 * Return: Number of characters printed
 */
int print_unsigned_number(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_unsigned_number(n / 10);
	_pchar(n % 10 + '0');
	count++;
	return (count);
}

/**
 * print_octal_number - Print an unsigned integer in octal format
 * @n: Unsigned integer to print
 * Return: Number of characters printed
 */
int print_octal_number(unsigned int n)
{
	int count = 0;

	count += (n / 8) ? print_octal_number(n / 8) : 0;
	_pchar (n % 8 + '0');
	count++;
	return (count);
}
