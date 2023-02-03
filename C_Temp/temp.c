#include <stdio.h>

int main()
{
    void *k;
    int a = 5, *j;

    j = k = &a;

    printf("%u %u", j++, k++);
    return 0;
}

int out = 100;