#include "parity.h"

char generateParityBit(char *data, int size)
{
    int res = 0;

    for (int i = 0; i < size; i++)
    {
        res ^= (data[i] - '0');
    }

    if (res == 0)
        return '0';

    return '1';
}


int isError(char *data, int size)
{
    int res = 0;

    for (int i = 0; i < size; i++)
    {
        res ^= (data[i] - '0');
    }

    return res;
}