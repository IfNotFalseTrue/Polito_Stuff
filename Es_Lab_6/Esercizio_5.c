#include <stdio.h>
#include <stdlib.h>


static int int_power(int base, int exponent)
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
    int a , b;
    
    scanf("%d%d", &a, &b);
    printf("%d\n", int_power(a, b));

    return EXIT_SUCCESS;
}

