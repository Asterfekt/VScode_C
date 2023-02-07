#include "inc/libfunc.h"
#include <stdio.h>


void probability(int x,int y)
{
    double probability =x*y;
    printf(" Masz %.2lf%% szansy trafienia ",1/probability*100);    
}