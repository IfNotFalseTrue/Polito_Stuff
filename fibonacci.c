/*
Successione di Fibonacci.
Non tiene conto di eventuali overflow, perché sono pigro.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 20 - 1


int main(void)
{
    int a[2] = {0, 1};
    int i;

    printf( "N°[0] = %d\n"
            "N°[1] = %d\n",
            a[0], a[1]);

    for (i = 0; i < MAX_N; ++i) {
        int j = i & 1;
        a[j] += a[j ^ 1];
        printf("N°[%d] = %d\n", i + 2, a[j]);
    }

    return EXIT_SUCCESS;
}
