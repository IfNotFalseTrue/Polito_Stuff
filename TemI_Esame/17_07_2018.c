/* Turno qualcosa.
Soluzione con vettore di stringhe, rispetto alla struct fatta a lezione.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_S 80
#define N 200
#define TRUE 1
#define FALSE 0


static void lower_case(char *s)
{
    while(*s != '\0') {
        *s = tolower(*s);
        ++s;
    }
}

static void string_swap(char *a, char *b)
{
    char tmp[MAX_S];
    strcpy(tmp, a);
    strcpy(a, b);
    strcpy(b, tmp);
}

static char search_string
(const char haystack[N][MAX_S], const char *needle, size_t dim)
{
    size_t i;
    char found = FALSE;

    for(i = 0; i < dim && !found; ++i) {
        if(strcmp(haystack[i], needle) == 0) {
            found = TRUE;
        }
    }

    return found;
}

static void sort_words(char v[N][MAX_S], size_t len)
{
    size_t i, j;
    char swapped = FALSE;
    len -= 1;
    char temp[MAX_S];

    for(i = 0; i < len && !swapped; ++i) {
        swapped = TRUE;
        for(j = 0; j < len - i; ++j) {
            if(strlen(v[j]) < strlen(v[j + 1]) ||
            (strlen(v[j]) == strlen(v[j + 1]) && strcmp(v[j], v[j + 1]) > 0)) {
                string_swap(v[j], v[j + 1]);
                swapped = FALSE;
            }
        }
    }
}


int main(int argc, char **argv)
{
    char words[N][MAX_S];
    char s[MAX_S];
    FILE *fp;
    size_t i, ct;

    if(argc != 2) {
        printf("Errore nei parametri da riga di comando\n");
        printf("Utilizzo: %s nomefile.txt\n", argv[0]);
        exit(EXIT_FAILURE);
    }


    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        puts("Errore apertura del file...");
        exit(EXIT_FAILURE);
    }

    ct = 0;
    while(fscanf(fp, "%s", s) == 1) {
        lower_case(s);
        if(!search_string(words, s, ct)) {
            strcpy(words[ct], s);
            ++ct;
        }
    }

    fclose(fp);

    if(ct != 0) {    //Se il file non e' vuoto...
        sort_words(words, ct);
        for(i = 0; i < ct; ++i) {
            printf("%s\n", words[i]);
        }
    }

    return EXIT_SUCCESS;
}
