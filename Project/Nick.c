#include <stdio.h>  // do skorzystania z printf
#include <stdlib.h> // do skorzystania z funkcji malloc
#include <string.h> // do skorzystania z strcpy,strlen
#include "inc/libfunc.h"


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