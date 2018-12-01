/*
Si scriva un programma C che
a. nel main chieda all’utente di inserire N valori e li metta in un vettore vett,
quindi chieda un ulteriore valore x
b. passi sia il vettore sia x ad una funzione che moltiplichi ciascuno degli
elementi del vettore per x e il cui prototipo sia
void mult(int v[], int n, int x);
Il main poi visualizzi il vettore dopo la moltiplicazione.
Nota bene: la funzione riceve il vettore per riferimento e quindi può modificare i
valori stessi del vettore. 
*/

#include <stdio.h>
#include <stdlib.h>
#define N 5UL

static float over_Avg (int v[], size_t n, int *superiori)
{
    float sum = 0;
    float avg;
    size_t i;

    for(i = 0; i < n; ++i) {
        sum += v[i];
    }
    
    avg = sum/n;
    
    for(i = 0; i < n; ++i) {
        if(v[i] > avg) {
            ++(*superiori);
        }
    }

    return avg;
}


int main(void)
{   
    int v[N];
    size_t i;
    int superiori = 0;

    for(i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }

    printf("La media dei valori e' %.2f ed il numero di elementi che la superano e' %d\n",
            over_Avg(v, N, &superiori), superiori);

    return EXIT_SUCCESS;
}

