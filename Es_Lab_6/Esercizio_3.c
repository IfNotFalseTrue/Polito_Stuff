#include <stdio.h>
#include <stdlib.h>
#define N 5UL
#define TRUE 1
#define FALSE 0

static void count_occ(int *v, size_t len)
{
    size_t i, j;
    size_t ct = 0;
    char found[N] = {FALSE};

    for(i = 0; i < len; ++i) {
        if(!found[i]) {
            ct = 1;
            for(j = i + 1; j < len; ++j) {
                if(v[i] == v[j]) {
                    ++ct;
                    found[j] = TRUE;
                }
            }
            printf("L'elemento %d compare %lu %s\n", 
                    v[i], ct, (ct > 1) ? "volte" : "volta");
        }
    }
}


int main(void)
{
    int v[N];
    size_t i;
    
    for(i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }

    count_occ(v, N);

    return EXIT_SUCCESS;
}

