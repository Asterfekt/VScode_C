#include "inc/libfunc.h"
#include <stdio.h>
#include <windows.h>

void loading()
{
    int i;
    char spinning_wheel[] = {'|', '/', '-', '\\'};

    for (i = 0; i < 40; i++)
    {
        printf("\r Loading.... %c", spinning_wheel[i % 4]);
        fflush(stdout);
        Sleep(100);
    }

    
}