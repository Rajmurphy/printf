#include "main.h"

/**
 * _myput - print string
 * @str: the string to be written
 * Return: the length of the string
*/

int _myput(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_pchar(str[i]);
	return (i);
}
