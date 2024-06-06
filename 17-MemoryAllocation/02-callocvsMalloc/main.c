#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    srand(time(0));

    int size = 0;
    int *junk = 0;

    for (int i = 0; i < 1000; i++)
    {
        size = rand() % 16000;
        junk = malloc(size * sizeof(int));

        for(int j = 0; j < size; j++) {
            junk[j] = rand();
        }

        free(junk);
    }
    

    int *array;
    array = malloc(1000 * sizeof(int));

    for (int i = 0; i < 1000; i++)
    {
        printf("%d", array[i]);
    }

    free(array);

    printf("\n");

    return 0;
    
}