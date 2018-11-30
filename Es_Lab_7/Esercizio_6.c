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
