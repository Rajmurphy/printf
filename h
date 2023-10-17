#include "main.h"

/**
 * printBinary - int argument is converted to binary
 * @n: number to be converted
 * Return: number of Binary tp be printed
 */

int print_binary(unsigned int n)
{
    if (n == 0)
    {
        return _pchar('0');
    }

    unsigned int mask = 1U << (sizeof(unsigned int) * 8 - 1);
    int count = 0;

    int started = 0;
    while (mask)
    {
        if (n & mask)
        {
            count += _pchar('1');
            started = 1;
        }
        else if (started)
        {
            count += _pchar('0');
        }
        mask >>= 1;
    }
