#include "main.h"

void printBinary(unsigned int n) 
{
    int binary[32];
    int i = 0;
    int j;

    if (n == 0) {
        putchar('0');
        return;
    }

    while (n > 0) 
    {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (j = i - 1; j >= 0; j--) {
        putchar('0' + binary[j]); 
    }
    putchar('\n');
}
