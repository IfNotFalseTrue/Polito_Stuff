#include <stdio.h>
#include <stdlib.h>
#define ROWS 5
#define COLUMNS 5
#define LEN_SEQ 3
#define VALUE 0


int main(void)
{
    int matrix [ROWS][COLUMNS]; /*= {{0, 0, 0, 4, 5},
                                  {1, 2, 0, 4, 5},
                                  {1, 0, 0, 4, 0},
                                  {1, 2, 3, 4, 5},
                                  {1, 0, 0, 0, 0}
                                  };*/
    size_t i, j;
    unsigned int ct;

    for(i = 0; i < ROWS; ++i)  {
        for(j = 0; j < COLUMNS; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(i = 0; i < ROWS; ++i) {
        ct = 0;
        for(j = 0; j < COLUMNS; ++j) {
            if(matrix[i][j] == VALUE) {
                ++ct;
            }
            else { 
                if(ct >= LEN_SEQ) {
                    printf("La sequenza di %d compare nella riga %lu\n", VALUE, i + 1);
                }
            ct = 0;
            }
        }
        if(ct >= LEN_SEQ) {
                printf("La sequenza di %d compare nella riga %lu\n", VALUE, i + 1);
        }
    }

    for(j = 0; j < COLUMNS; ++j) {
        ct = 0;
        for(i = 0; i < ROWS; ++i) {
            if(matrix[i][j] == VALUE) {
                ++ct;
            }
            else { 
                if(ct >= LEN_SEQ) {
                    printf("La sequenza di %d compare nella colonna %lu\n", VALUE, j + 1);
                }
            ct = 0;
            }
        }
        if(ct >= LEN_SEQ) {
                printf("La sequenza di %d compare nella colonna %lu\n", VALUE, j + 1);
        }
    }

    return EXIT_SUCCESS;
}
