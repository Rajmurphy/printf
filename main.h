#ifndef MAIN_HEADER_H
#define MAIN_HEADER_H

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
<<<<<<< HEAD
=======
void printBinary(unsigned int n);
char *_reverse(char *str);
>>>>>>> b346efd01ac457a86009d72c836d54133a0db696

#endif
