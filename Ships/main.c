#include <stdio.h>
#include <stdlib.h> // do skorzystania z RAND

#define x 5
#define y 5

int main()
{

    int i, j=0;
    int Gx,Gy;
    printf("Wybierz cel : \n");
    printf("Wybierz x : ");scanf("%d", &Gx);
    printf("Wybierz y : ");scanf("%d", &Gy);
    printf("Wybrales : [%d,%d] \n",Gx,Gy);
    
   int Rx=rand()%4;
    int Ry=rand()%4;
 

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            if(Gx==i && Gy==j)
            {
                printf("[%c,%c]: ",'x','x');}
            else
            printf("[%d,%d]: ",i,j);
           
        }

 
        printf("\n");

    }
    printf("Pozycja Wygrana\n");
   printf("[%d,%d]\n",Rx,Ry);
if (Rx==Gx && Ry==Gy)
{
      printf("Wygrales\n");
}
else
 printf("Przegrales\n");
    
    return 0;
}