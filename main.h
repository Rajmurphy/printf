#ifndef MAIN_HEADER_H
#define MAIN_HEADER_H
#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)
#define F_HASH 0x01

/* C Standard library header files*/
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int _printf(const char *format, ...);
int _pchar(char a);
int _myput(char *str);
int print_arg(char spec, va_list args);
int print_number(int n);
void printBinary(unsigned int n);
char *_reverse(char *str);
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_base(va_list types, char map_to[], char buffer[],
              int flags, char flag_ch, int base, int width, int precision, int size);
int write_unsgnd(int fd, int i, char buffer[], int flags, int width, int precision, int size);


#endif
