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
int print_hex_number(unsigned int n, char spec);
int print_octal_number(unsigned int n);
int print_unsigned_number(unsigned int n);
int handle_specifier(char spec, va_list args);

#endif
