#include <stdio.h>  // do skorzystania z printf
#include <stdlib.h> // do skorzystania z funkcji malloc
#include <string.h> // do skorzystania z strcpy,strlen
#define MAX_NICKS 100
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
/*Podawanie Nicku*/
char *getNick()
{
    char buffer[100];
    printf("Podaj swoj nick: \n ");
    scanf("%s", buffer);

    int size = strlen(buffer) + 1; // srtlen do zwrócenia długości ciągów znaków
    char *nick = (char *)malloc(size * sizeof(char));
    if (nick == NULL)
    {
        printf("Nie udało się zaalokowac pamieci.\n");
        exit(1);
    }
    strcpy(nick, buffer); // przepisanie ciągu znaków
    printf("%s\n", nick);

    return nick;
}
/*Struktura */
struct Player
{
    char *nickname;
    int points;
};

int main()
{
    struct Player Nick;
    Nick.nickname = getNick();

    printf("koniecc i koncowy wynik to %s \n", Nick.nickname);

    printf("Podaj wartosc dla nicka: \n ");
    scanf("%d", &Nick.points);

    FILE *f = fopen("nick.txt", "a");
    if (f == NULL)
    {
        printf("Nie udalo się otworzyc pliku.\n");
        exit(1);
    }

    fprintf(f, "%s %d \n", Nick.nickname, Nick.points);
    fclose(f);

    free(Nick.nickname);
    FILE *d = fopen("nick.txt", "r");

    if (d == NULL)
    {
        printf("Nie udało się otworzyć pliku.\n");
        exit(1);
    }

    char nickname[100];
    int value;

    while (fscanf(d, "%s %d", nickname, &value) == 2)
    {
        printf("%s %d\n", nickname, value);
    }

    fclose(d);
    /*Sortowanie Bombelkowe */
    FILE *e = fopen("nick.txt", "r");

    if (e == NULL)
    {
        printf("Nie udało się otworzyć pliku.\n");
        exit(1);
    }

    struct NickValue nicks[MAX_NICKS];
    int n = 0;

    while (fscanf(e, "%s %d", nicks[n].nickname, &nicks[n].value) == 2)
    {
        n++;
    }

    fclose(e);

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

    e = fopen("nick.txt", "w");

    if (e == NULL)
    {
        printf("Nie udało się otworzyć pliku.\n");
        exit(1);
    }

    for (i = 0; i < n; i++)
    {
        fprintf(e, "%s %d\n", nicks[i].nickname, nicks[i].value);
    }

    fclose(e);

    return 0;
}

/*{

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
}*/
