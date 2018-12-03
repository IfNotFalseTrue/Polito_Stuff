#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define N 5UL


static void xor_swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

static void input_array(int *a, size_t len)
{
    size_t i;
    
    for(i = 0; i < len; ++i) {
        scanf("%d", &a[i]);
    }
}

static void bubble_sort(int *v, size_t len)
{
    size_t i, j;
    char swapped = TRUE;
    len -= 1;

    for(i = 0; i < len && swapped; ++i) {
        swapped = FALSE;
        for(j = 0; j < len - i; ++j) {
            if(v[j] > v[j + 1]) {
                xor_swap(&v[j], &v[j + 1]);
                swapped = TRUE;
            }
        }
    }
}


static char cmp_arrays(int *v1, int *v2, size_t len)
{
    size_t i = 0;
    char equals = TRUE;

    for(i = 0; i < len && equals; ++i) {
        if(v1[i] != v2[i]) {
            equals = FALSE;
        }
    }

    return equals;
}


int main(void)
{
    int v1[N];
    int v2[N];

    input_array(v1, N);
    input_array(v2, N);

    bubble_sort(v1, N);
    bubble_sort(v2, N);

    printf("I 2 vettori %scontengono gli stessi elementi\n",
            cmp_arrays(v1, v2, N) ? "" : "non ");

    return EXIT_SUCCESS;
}

