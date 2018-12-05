#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BUFSIZE 128
#define TRUE 1
#define FALSE 0


static void remove_new_line(char *s)
{
    char *p = strrchr(s, '\n');
    if (NULL != p) {
        *p = '\0';
    }
}

static void count_occ(const unsigned int *v, size_t len)
{
    size_t i, j;
    unsigned int ct = 0;
    char found[BUFSIZE] = {FALSE};
    
    for(i = 0; i < len; ++i) {
        if(!found[i]) {
            ct = 1;
            for(j = i + 1; j < len; ++j) {
                if(v[i] == v[j]) {
                    ++ct;
                    found[j] = TRUE;
                }
            }
            printf("-%u %s da %u caratteri\n", 
                    ct, (ct > 1) ? "parole" : "parola", v[i]);
        }
    }
}


int main(void)
{
    char s[BUFSIZE];
    unsigned int w_lengths[BUFSIZE] = {0};
    unsigned int single_len;
    size_t i, j, len;
    char in_w = FALSE;
    double tot_len_w = 0;
    unsigned int w_c = 0;


    fgets(s, BUFSIZE, stdin);
    remove_new_line(s);

    len = strlen(s);
    j = 0;
    single_len = 0;

    for(i = 0; i < len; ++i) {
        if(isspace(s[i])) {
            in_w = FALSE;
            w_lengths[j] = single_len;
            single_len = 0;
            ++j;
        }
        else if(in_w == FALSE) {
            in_w = TRUE;
            ++w_c;
            ++tot_len_w;
            ++single_len;
        }
        else {
            ++tot_len_w;
            ++single_len;
        }
    }

    /*ACHTUNG: all'uscita del ciclo j vale il numero delle parole - 1 ( w_c - 1)*/
    w_lengths[j] = single_len;
    ++j;

    printf("La stringa inserita contiene %u %s\n", 
            w_c, (w_c == 0 || w_c > 1) ? "parole" : "parola");

    if(w_c != 0) {
        printf("La lunghezza media delle parole e' %.1lf\n", tot_len_w / w_c);
        count_occ(w_lengths, j);
    }

    return EXIT_SUCCESS;
}

