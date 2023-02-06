#include <stdio.h>  // do skorzystania z printf
#include <stdlib.h> // do skorzystania z funkcji malloc
#include <string.h> // do skorzystania z strcpy,strlen
#include "inc/libfunc.h"
#include "inc/libstruct.h"
#include <windows.h>

#define LEN 100

/*Sortowanie*/
struct NickValue
{
    char nickname[100];
    int value;
};
void swap(struct NickValue *a, struct NickValue *b)
{
    struct NickValue temp = *a;
    *a = *b;
    *b = temp;
}
int main()

{
    int x = 1;
    int y = 1;
    int i, j = 0;
    int Gx, Gy;
    int wybor = 0;
    struct Player Nick;
    Nick.nickname = getNick();
    printf("koniecc i koncowy wynik to %s \n", Nick.nickname);
    Nick.points = 0;

    while (wybor != 4)
    {
        system("cls");
        Sleep(2000);
        printf("Gracz: %s Punkty: %d \n", Nick.nickname, Nick.points);
        printf(" \n ");
        printf("[1] START \n ");
        printf("[2] Tablica Wynikow \n ");
        printf("[3] Version \n ");
        printf("[4] Wyjscie \n ");
        scanf("%d", &wybor);
        FILE *f;
        switch (wybor)
        {
        case 1:

            printf("Wybierz cel : \n");
            printf("Wybierz x : ");
            scanf("%d", &Gx);
            printf("Wybierz y : ");
            scanf("%d", &Gy);
            printf("Wybrales : [%d,%d] \n", Gx, Gy);
            printf(" \n ");
            Sleep(500);
            int Rx = rand() % x;
            int Ry = rand() % y;

            for (i = 0; i < x; i++)
            {
                for (j = 0; j < y; j++)
                {
                    if (Gx == i && Gy == j)
                    {
                        printf("[%c,%c]: ", 'x', 'x');
                    }
                    else
                        printf("[%d,%d]: ", i, j);
                }
                Sleep(1500);
                printf("\n");
            }
            printf("Pozycja Wygrana\n");
            Sleep(1500);
            printf("[%d,%d]\n", Rx, Ry);
            if (Rx == Gx && Ry == Gy)
            {
                printf("Wygrales\n");
                Nick.points += 3;
            }
            else
                printf("Przegrales\n");
            Sleep(3000);

            break;
        case 2:
            ////////////////////////////////////////////

            f = fopen("nick.txt", "a");
            if (f == NULL)
            {
                printf("Nie udalo się otworzyc pliku.\n");
                exit(1);
            }

            fprintf(f, "%s %d \n", Nick.nickname, Nick.points);
            fclose(f);

            free(Nick.nickname);

            /*Sortowanie Bombelkowe */
            f = fopen("nick.txt", "r");

            if (f == NULL)
            {
                printf("Nie udało się otworzyć pliku.\n");
                exit(1);
            }

            struct NickValue nicks[LEN];
            int n = 0;

            while (fscanf(f, "%s %d", nicks[n].nickname, &nicks[n].value) == 2)
            {
                n++;
            }

            fclose(f);

            int i, j;
            for (i = 0; i < n - 1; i++)
            {
                for (j = 0; j < n - i - 1; j++)
                {
                    if (nicks[j].value < nicks[j + 1].value)
                    {
                        swap(&nicks[j], &nicks[j + 1]);
                    }
                }
            }

            f = fopen("nick.txt", "w");

            if (f == NULL)
            {
                printf("Nie udało się otworzyć pliku.\n");
                exit(1);
            }

            for (i = 0; i < n; i++)
            {
                fprintf(f, "%s %d\n", nicks[i].nickname, nicks[i].value);
            }

            fclose(f);
            f = fopen("nick.txt", "r");

            if (f == NULL)
            {
                printf("Nie udało się otworzyć pliku.\n");
                exit(1);
            }

            char nickname[100];
            int value;

            while (fscanf(f, "\t\t %s %d", nickname, &value) == 2)
            {
                printf("%s %d\n", nickname, value);
            }
            Sleep(3000);
            fclose(f);

            break;
        case 3:
            printf("Version 1.0 Autor M.Krzysciak \n");
            Sleep(3000);
            break;

        default:
            printf("Dziekuje %s uzyskales %d punktow zapraszam ponownie", Nick.nickname, Nick.points);
            break;
        }
    }
    return 0;
}
