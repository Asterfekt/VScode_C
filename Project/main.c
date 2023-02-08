#include <stdio.h>  // printf
#include <stdlib.h> // malloc
#include <string.h> // strcpy,strlen
#include "inc/libfunc.h"
#include <windows.h> //Sleep
#define LEN 100

struct NickValue
{
    char *nickname;
    int value;
};

int compare(const void *a, const void *b)
{
    struct NickValue *x = (struct NickValue *)a;
    struct NickValue *y = (struct NickValue *)b;
    return y->value - x->value;
}
int main()

{
    int life = 3;
    char znak;
    int level = 0;
    int x;
    int y;
    int i, j = 0;
    int Gx, Gy;
    int wybor = 0;
    struct NickValue Nick;
    FILE *f;
    Nick.nickname = getNick();
    Nick.value = 0; // Początkowa wartość punktów

    while (wybor != 4)
    {
        if (wybor == 1)
        {
            Nick.nickname = getNick();
            Nick.value = 0; // Początkowa wartość punktów
        }
        else
        life = 3; // 3 serduszka
        system("cls");
        loading();
        system("cls");
        printf("Gracz: %s Punkty: %d \n", Nick.nickname, Nick.value);
        printf(" \n ");
        printf("[1] START \n ");
        printf("[2] Tablica Wynikow \n ");
        printf("[3] Version \n ");
        printf("[4] Wyjscie \n ");
        printf(" \n ");
        scanf("%d", &wybor);
        switch (wybor)
        {
        case 1: /* Start  GRY*/

            printf("Wybierz poziom: \n ");
            printf("[1] Latwy 3x3\n ");
            printf("[2] Sredni 4x4 \n ");
            printf("[3] Trudny 5x5\n ");
            printf("[4] Wlasny \n ");
            scanf("%d", &level);

            if (level == 1)
            {
                x = 3;
                y = 3;
            }
            else if (level == 2)
            {
                x = 4;
                y = 4;
            }
            else if (level == 3)
            {
                x = 5;
                y = 5;
            }
            else if (level == 4)
            {
                printf("Wybierz liczbe wierszy : ");
                scanf("%d", &x);
                printf("Wybierz liczbe kolumn : ");
                scanf("%d", &y);
                printf(" \n");
            }
            while (life != 0)
            {
                int Rx = rand() % x;
                int Ry = rand() % y;
                printf("Gracz: %s Punkty: %d \n", Nick.nickname, Nick.value);
                probability(x, y);
                printf(" \n");
                printf("Masz %d serca \n ", life);
                printf("Wybierz cel : \n");
                printf(" \n");
                printf("Wiedzac ze x  \n");
                parity(Rx);
                printf("Wybierz x : ");
                scanf("%d", &Gx);
                printf("Wiedzac ze y  \n");
                parity(Ry);
                printf("Wybierz y : ");
                scanf("%d", &Gy);
                printf("Wybrales : [%d,%d] \n", Gx, Gy);
                printf(" \n ");
                Sleep(100);
                for (i = 0; i < x; i++)
                {
                    for (j = 0; j < y; j++)
                    {

                        if (Rx == Gx && Ry == Gy && Rx == i && Ry == j && Gx == i && Gy == j)
                        {
                            printf("[%c,%c]: ", 'C', 'C');
                        }

                        else if (Rx == i && Ry == j)
                        {
                            printf("[%c,%c]: ", 'o', 'o');
                        }
                        else if (Gx == i && Gy == j)
                        {
                            printf("[%c,%c]: ", 'x', 'y');
                        }

                        else
                        {
                            printf("[%d,%d]: ", i, j);
                        }
                    }
                    printf("\n");
                    Sleep(500);
                    printf("\n");
                }
                printf("Pozycja Wygrana\n");
                Sleep(500);

                printf("[%d,%d]\n", Rx, Ry);
                printf("\n");
                if (Rx == Gx && Ry == Gy)
                {
                    printf("Wygrales\n");
                    if (life == 3)
                    {
                        Nick.value += 3;
                    }
                    else if (life == 2)
                    {
                        Nick.value += 2;
                    }
                    else
                        Nick.value += 1;

                    life += 1;
                }
                else
                    printf("Przegrales tracisz 1 zycie \n");
                Sleep(2000);
                life -= 1;
                system("cls");
            }
            Sleep(1000);

            /* Zapisanie wyniku do pliku  */

            f = fopen("nick.txt", "a");
            if (f == NULL)
            {
                printf("Nie udalo się otworzyc pliku.\n");
                exit(1);
            }

            fprintf(f, "%s %d\n", Nick.nickname, Nick.value);
            fclose(f);

            free(Nick.nickname);

            break;

        case 2: /* Tabela wyników     */

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

            Sleep(2000);
            fclose(f);
            break;

        case 3: /* Version  */
            printf("Version 1.0 Autor M.Krzysciak \n");
            Sleep(3000);
            break;

        default: /* Koniec  */
            printf("Dziekuje %s uzyskales %d punktow zapraszam ponownie", Nick.nickname, Nick.value);
            Sleep(2000);
            break;
        }
    }

    /*Otwarcie pliku */
    f = fopen("nick.txt", "r");
    if (f == NULL)
    {
        printf("Nie udalo się otworzyc pliku.\n");
        exit(1);
    }
    struct NickValue nicks[LEN];
    int n = 0;
    while (fscanf(f, "%s %d", nicks[n].nickname, &nicks[n].value) == 2)
    {
        n++;
    }
    fclose(f);

    /*Sortowanie*/
    qsort(nicks, n, sizeof(struct NickValue), compare);
    f = fopen("nick.txt", "w");
    if (f == NULL)
    {
        printf("Nie udalo się otworzyc pliku.\n");
        exit(1);
    }
    int k;
    for (k = 0; k < n; k++)
    {
        fprintf(f, "%s %d\n", nicks[k].nickname, nicks[k].value);
    }
    fclose(f);

    return 0;
}