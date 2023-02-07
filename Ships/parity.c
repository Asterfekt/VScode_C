#include "inc/libfunc.h"
#include <stdio.h>

void parity(int x)
{
    if (x % 2 == 0)
    {
        printf("Jest parzyste.\n");
    }
    else
    {
        printf("nie jest parzyste.\n");
    }
}