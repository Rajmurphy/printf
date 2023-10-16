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
	if (format == NULL)
		return (-1);
	va_list args;

	int count = 0;
	int i, len;
	char spec;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_pchar(format[i]);
			count++;
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
		{
			va_end(args);
			return (-1);
		}
		else if (format[i] == '%' && format[i + 1] != '%')
		{
			i++;
			spec = format[i];

			if (spec == 'c')
			{
				_pchar(va_arg(args,  int));
				count++;
			}
			else if (spec == 's')
			{
				char *str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				len = 0;

				while (str[len])
				{
					_pchar(str[len]);
					len++;
				}
				count += len;
			}
			else if (spec == 'd' || spec == 'i')
			{
				int num = va_arg(args, int);
				count += print_number(num);
			}
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			_pchar('%');
			count++;

			i++;
		}
	}

	va_end(args);
	return (count);
}

/**
* print_number - Print an integer
* @n: Integer to print
* Return: Number of characters printed
*/
int print_number(int n)
{
	int count = 0;

	if (n < 0)
	{
		_pchar('-');
		count++;
		n = -n;
	}
	if (n / 10)
		count += print_number(n / 10);
	_pchar(n % 10 + '0');
	count++;

	return (count);
}
