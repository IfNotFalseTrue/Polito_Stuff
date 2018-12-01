#include <stdio.h>
#include <stdlib.h>
#define N 5UL

static void mult(int v[], size_t n, int x)
{
    size_t i;

    for(i = 0; i < n; ++i) {
        v[i] *= x; 
    }
}

int main(void)
{   
    int v[N];
    int x;
    size_t i = 0;

    for(i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }
    scanf("%d", &x);

    mult(v, N, x);

    for(i = 0; i < N; ++i) {
        printf("%d ", v[i]);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}

