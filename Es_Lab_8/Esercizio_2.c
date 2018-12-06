/*
Esercizio 2. Si scriva un programma C che:
a. Acquisisca una stringa di massimo N caratteri (con N valore costante)
b. Ne manipoli il contenuto
i. Trasformando tutte le lettere minuscole in maiuscole
ii. Rimpiazzando tutti i caratteri non alfanumerici con il carattere ‘_’
iii. Sostituendo i caratteri numerici con il carattere ‘*’
c. Scandisca la stringa manipolata per contare quante parole sono
presenti al suo interno, considerando una o più occorrenze del
carattere ‘_’ come separatore tra parole.
Approfondimento: l’ordine in cui vengono eseguite le manipolazioni
influenza il risultato? Verificare la risposta scrivendo due versioni del
programma che manipolino la stringa in modi differenti. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define BUFSIZE 128UL
#define TRUE 1
#define FALSE 0


static void remove_new_line(char *s)
{
    char *p = strrchr(s, '\n');
    if (NULL != p) {
        *p = '\0';
    }
}


static void lower_to_upper(char *s, size_t len)
{
    size_t i;
    for(i = 0; i < len; ++i) {
        s[i] = toupper(s[i]);
    }
}

/*Sostituisce caratteri non alfanumerici con _*/
static void replace_alpha_ch(char *s, size_t len, char sub)     
{
    size_t i = 0;
    for(i = 0; i < len; ++i) {
        if(!isalpha(s[i])) {
            s[i] = sub;
        }
    }
}

static void replace_num_ch(char *s, size_t len, char sub)
{
    size_t i = 0;
    for(i = 0; i < len; ++i) {
        if(isdigit(s[i])) {
            s[i] = sub;
        }
    }
}

static unsigned int count_words(const char *s, size_t len, int delim)
{
    size_t i = 0;
    char in_w = FALSE;
    unsigned int w_c = 0;

    for(i = 0; i < len; ++i) {
        if(s[i] == delim) {
            in_w = FALSE;
        }
        else if(!in_w) {
            in_w = TRUE;
            ++w_c;
        }
    }

    return w_c;
}

int main(void)
{   
    char s[BUFSIZE];
    size_t len;
    unsigned int w_c = 0;

    fgets(s, BUFSIZE, stdin);
    remove_new_line(s);

    len = strlen(s);
    
    lower_to_upper(s, len);
    replace_alpha_ch(s, len, '_');
    replace_num_ch(s, len, '*');

    puts(s);
    w_c = count_words(s, len, '_');

    printf("Nella stringa ci sono %u %s\n",
            w_c, (w_c == 0 || w_c > 1) ? "parole" : "parola");

    return EXIT_SUCCESS;
}
