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
	int i, j, count = 0;
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
			else if (spec == 'd' || spec == 'i')
				count += print_number(va_arg(args, int));
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
 * _reverse - Reverses a string
 * @str: The string to reverse
 * Return: Pointer to the reversed string
 */
char *_reverse(char *str)
{
	int i, j, len = 0;
	char temp;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}

	return (str);
}
