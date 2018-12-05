/*
Esercizio 1. Si scriva un programma che:
a. Definisca un vettore di caratteri e acquisisca una stringa al suo interno
b. Analizzi tale stringa rispondendo alle seguenti domande
i. Quanto è lunga la stringa?
ii. Quanti caratteri sono alfabetici e quanti numerici?
Approfondimento: acquisita una seconda stringa, stabilire se quest’ultima
è inclusa nella prima (ad esempio: “importante” include “porta”)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BUFSIZE 128

static void remove_new_line(char *s)
{
    char *p = strrchr(s, '\n');
    if (NULL != p) {
        *p = '\0';
    }
}


int main(void)
{
    char s[BUFSIZE];
    size_t len;
    size_t i;
    unsigned int alpha_chs = 0;
    unsigned int num_chs = 0;

    fgets(s, BUFSIZE, stdin);
    remove_new_line(s);

    len = strlen(s);

    printf("La stringa inserita e' lunga %lu caratteri\n", len);

    for(i = 0; i < len; ++i) {
        if(isalpha(s[i])) {
            ++alpha_chs;
        }
        else if(isdigit(s[i])) {
            ++num_chs;
        }
    }

    printf("La stringa inserita contiene %u caratteri alfabetici\n", alpha_chs);
    printf("La stringa inserita contiene %u caratteri numerici\n", num_chs);

    return EXIT_SUCCESS;
}

