#include "main.h"
/**
 * _pchar - print a character
 * @a: parmeter
 * Return: the result
 */

int _pchar(char a)
{
	return (write(1, &a, 1));
}
