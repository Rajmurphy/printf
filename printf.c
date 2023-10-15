#include "main.h"
/**
 * _printf - prints output
 * main - calls the function
 * @format - character string
 */

int _printf(const char *format, ...)
{
int chara = 0;
va_list args;
if (format == NULL)
return (-1);
va_start(args, format);
for (; *format; format++)
{
if (*format != '%')
{
write(1, format, 1);
chara++;
}
else
{
format++;
if (*format == 'c' || *format == '%')
{
char c = (*format == 'c') ? va_arg(args, int) : '%';
write(1, &c, 1);
chara++;
}
else if (*format == 's')
{
char *str = va_arg(args, char*);
for (int i = 0; str[i]; i++)
{
write(1, &str[i], 1);
chara++;
}
}
}
}
va_end(args);
return (chara);
}
int main(void)
{
_printf("Example\n");
_printf("%c\n", 'v');
_printf("%s\n", "String");
_printf("%%\n");
return (0);
}
