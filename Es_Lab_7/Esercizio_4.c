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

