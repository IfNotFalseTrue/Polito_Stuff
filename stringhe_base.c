/*
Alcune funzioni utili su come trattare le stringhe:

1) Contare il numero di parole
2) Verificare o meno se la parola è palindroma ( si adatta facilmente ad un vettore)
3) Invertire la stringa
4) Rimuovere il '\n' finale lasciato da fgets
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 128
#define FALSE 0
#define TRUE 1


/*
Nel caso in cui si vogliano considerare gli spazi come separatore,
usare isspace definita in ctype.h
*/ 
static unsigned int count_words(char *s, size_t len, char separator)
{
    size_t i = 0;
    unsigned int words_count = 0;
    char in_word = FALSE;
    
    for(i = 0; i < len; ++i) {
        if(s[i] == separator) {
            in_word = FALSE;
        }
        else if(in_word == FALSE) {
            in_word = TRUE;
            ++words_count;
        }
    }

    return words_count;
}


static void swap_ch(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}


static int is_palindrome(const char *s, size_t len)
{
    size_t i = 0;
    int pal = 0;

    len -= 1;

    for(i = 0; i < len/2 && !pal; ++i) {
        if(s[i] == s[len - i]) {
            pal = 1;
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

