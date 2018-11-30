/*Si realizzi un programma che permetta di inserire da tastiera un testo e che lo
stampi su video, cambiando in maiuscolo ogni carattere di inizio parola.
Ad esempio se in ingresso viene fornito il seguente testo:
 fatti non foste
 per viver come bruti
 ma per seguir virtute e canoscenza
 su video deve apparire così:
Fatti Non Foste
 Per Viver Come Bruti
Ma Per Seguir Virtute E Canoscenza 
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

    while((c = getchar()) != EOF) {
        if(isspace(c)) {
            putchar(c);
            in_word = FALSE;
        }
        else if(in_word == FALSE) {
            in_word = TRUE;
            putchar(toupper(c));
        }
        else {
            putchar(c);
        }
    }
    
    return EXIT_SUCCESS;
}
