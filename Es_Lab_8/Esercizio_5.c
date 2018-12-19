#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_S 64
#define N 3

static int search_product
(const char haystack[N][MAX_S], const char *needle, int dim)
{
    int i;
    int index = -1;

    for(i = 0; i < dim && index == -1; ++i) {
        if(strcmp(haystack[i], needle) == 0) {
            index = i;
        }
    }

    return index;
}

int main(void)
{
    char input[MAX_S];
    char products[N][MAX_S];
    double price[N];
    char my_product[MAX_S];
    int prod_index, i;
    unsigned int qtity = 0;
    int error_sscanf = EOF;

    printf("Inserisci %d prodotti e prezzi separati da spazio:\n", N);
    for(i = 0; i < N; ++i) {
        gets(input);
        error_sscanf = sscanf(input, "%s %lf", products[i], &price[i]);
        if(error_sscanf != 2) {
            puts("Errore nell'input...");
            exit(EXIT_FAILURE);
        }
    }

    do {
        puts("Inserisci il prodotto da cercare e la quantita':");
        gets(input);
        error_sscanf = sscanf(input, "%s %u", my_product, &qtity);
        prod_index = search_product(products, my_product, N);
        if(error_sscanf != 2) {
            puts("Errore nell'input...");
        }
        else if(prod_index == -1) {
            puts("Prodotto non trovato");
        }
        else {
            printf("Prezzo totale di %s: %.2lf\n", my_product, qtity * price[prod_index]);
        }

    } while(prod_index == -1 || error_sscanf != 2);

    return EXIT_SUCCESS;
}
