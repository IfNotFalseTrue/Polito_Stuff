#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define N 5UL


static char is_palindrome(const int *a, size_t len)
{
    size_t i = 0;
    char palindrome = TRUE;
    len -= 1;

    for(i = 0; i < len/2 && palindrome; ++i) {
        if(a[i] != a[len - i]) {
            palindrome = FALSE;
        }
    }

    return palindrome;
}


int main(void)
{   
    int v[N];
    size_t i = 0;

    for(i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }

    printf("Il vettore inserito %se' palindromo\n", is_palindrome(v, N) ? "" : "non ");

    return EXIT_SUCCESS;
}


