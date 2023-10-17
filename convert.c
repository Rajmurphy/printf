#include "main.h"

/**
 * printBinary - int argument is converted to binary
 * @n: number to be converted
 * Return: 0
 */

void printBinary(unsigned int n)
{
	int binary[32];
	int i = 0;
	int j;

	if (n == 0)
	{
		_pchar('0');
		return;
	}
	while (n > 0)
	{
		binary[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_pchar('0' + binary[j]);
	}
	_pchar('\n');
}
