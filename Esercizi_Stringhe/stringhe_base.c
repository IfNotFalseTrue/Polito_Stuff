/*
Alcune funzioni utili su come trattare le stringhe:
( Si adattano facilmente ad un vettore)
 
 
1) Verificare o meno se la parola è palindroma
2) Invertire la stringa
3) Rimuovere il '\n' finale lasciato da fgets
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 128
#define FALSE 0
#define TRUE 1

static void swap_ch(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}


static int is_palindrome(const char *s, size_t len)
{
    size_t i = 0;
    int pal = TRUE;

    len -= 1;

    for(i = 0; i < len/2 && pal; ++i) {
        if(s[i] != s[len - i]) {
            pal = FALSE;
        }
    }

    return pal;
}

static char *reverse_string(char *s, size_t len)
{
    size_t i = 0;

    len -= 1;

    for(i = 0; i < len/2; ++i) {
        swap_ch(&s[i], &s[len - i]);
    }

    return s;
}

//Necessaria per rimuovere il \n dalla fgets
static void remove_new_line(char *s)
{
    char *p = strrchr(s, '\n');
    if (NULL != p) {
        *p = '\0';
    }
}



int main(void)
{
    char s[MAX_SIZE];
    size_t len;

    fgets(s, MAX_SIZE, stdin);
    remove_new_line(s);
    len = strlen(s);

    if(len < 1) {
        exit(EXIT_FAILURE);
    }

    printf("%s al contrario : %s\n", s, reverse_string(s, len));
    printf("La stringa %s %se' palindroma\n", s, is_palindrome(s, len) ? "" : "non ");

    return EXIT_SUCCESS;
}


