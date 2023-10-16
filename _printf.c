#include "main.h"
#include <stdarg.h>
/**
* _printf - Custom printf implementation
* @format: Format string
* @...: Variable number of arguments
* @n: Integer to print
*Return: Number of characters printed
* print_number - Print an integer

*/

int _printf(const char *format, ...)
{
	va_list args;
	char spec = format[i];
	int i, count = 0;

    if (format == NULL)
        return -1;

    va_start(args, format);
    for (i = 0; format[i]; i++) {
        if (format[i] != '%') {
            _pchar(format[i]);
            count++;
        } else if (format[i] == '%' && format[i + 1] != '%') {
            i++;
            if (spec == 'c')
                _pchar(va_arg(args, int));
            else if (spec == 's') {
                char *str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    _pchar(*str++);
                    count++;
                }
            } else if (spec == 'd' || spec == 'i') {
                count += print_number(va_arg(args, int));
            }
        } else if (format[i] == '%' && format[i + 1] == '%') {
            _pchar('%');
            count++;
            i++;
        }
    }

    va_end(args);
    return count;
}
