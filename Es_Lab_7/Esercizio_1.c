/*
Si scriva un programma C che, dati due vettori di uguale dimensione N (vbase e
vexponent), elevi ciascun elemento del vettore vbase alla potenza indicata nell’elemento
di vexponent avente lo stesso indice (ossia vbase[i] elevato a vexponent[i]).
I risultati dovranno essere memorizzati nella corrispondente posizione di un terzo vettore denominato vres.
Si utilizzi la funzione power definita nel corso del precedente laboratorio e avente il seguente prototipo:
int power(int base, int exponent);
Vengano inseriti prima i valori delle N basi e poi quelli degli N esponenti; vengano alla fine visualizzati i valori di vres.
Esempio
Siano inseriti dall’utente i valori seguenti (per N pari a 5):
vbase
vexponent
5 2 7 4 9
2 6 1 8 3
Il vettore risultato sarà il seguente:
vres
25 64 7 65536 729
*/

#include <stdio.h>
#include <stdlib.h>
#define N 5UL


static void input_array(int *a, size_t dim)
{
    size_t i = 0;

    for(i = 0; i < dim; ++i) {
        scanf("%d", &a[i]);
    }
}

static int power(int base, int exponent)
{
    int result = 1;

    while(exponent != 0) {
        if((exponent & 1) != 0) {
            result *= base;
        }
        exponent >>= 1;
        base *= base;
    }

    return result;
}


int main(void)
{
    int v_base[N];
    int v_exponent[N];
    int v_res[N];
    size_t i;

    input_array(v_base, N);
    input_array(v_exponent, N);

    for(i = 0; i < N; ++i) {
        v_res[i] = power(v_base[i], v_exponent[i]);
    }

    for(i = 0; i < N; ++i) {
        printf("%d ", v_res[i]);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}

