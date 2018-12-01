/*
Si realizzi un programma in linguaggio C che analizzi un documento di tipo testo
costituito da un numero imprecisato di righe. Il documento viene caricato in input
tramite la tastiera. Il programma deve effettuare le seguenti operazioni:
- contare il numero totale di righe;
- contare il numero totale di parole;
- determinare la lunghezza media di una parola.
Ai fini di questo problema, si considera come parola una sequenza di caratteri
appartenenti tutti alla medesima riga e privi di spazi.
Ad esempio se in ingresso viene fornito il seguente documento:
 fatti non foste
 per viver come bruti
 ma per seguir virtute e canoscenza
 Il programma deve generare un output simile al seguente:
 Numero di righe: 3
 Numero di parole: 13
 Lunghezza media di una parola: 4.5 
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define TRUE 1
#define FALSE 0

int main(void)
{   
    int c;
    char in_word = FALSE;
    unsigned int words_count = 0;
    unsigned int lines_count = 0;
    double len_words = 0;

    while((c = getchar()) != EOF) {
        if(isspace(c)) {
            in_word = FALSE;
            if(c == '\n') {
                ++lines_count;
            }
        }
        else if(in_word == FALSE) {
            in_word = TRUE;
            ++words_count;
            ++len_words;
        }
        else {
            ++len_words;
        }
    }

    printf("Numero di righe: %u\n", lines_count);
    printf("Numero di parole: %u\n", words_count);
    printf("Lunghezza media di una parola: %.1lf\n", len_words/words_count);

    return EXIT_SUCCESS;
}
