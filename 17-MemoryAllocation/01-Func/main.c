#include <stdio.h>
#include <stdlib.h>


int main() {

    int size = 0;
    printf("\nEnter size: ");
    scanf("%d", &size);

    int *a = malloc( sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        a[i] = size -i;
    }

    for (int i = 0; i < size; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("\n");

    // printf("a: %p\n", a);

    // int *save = a;
    // free(a);
    // printf("\nsave = %p\n", save);

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("\nsave[%d] = %d\n", i, save[i]);
    // }
    
    // printf("\n");

    a = realloc(a, sizeof(int) * (size + 5));

    for (int i = size; i < (size + 5); i++)
    {
        a[i] = 9;
    }

    for (int i = size; i < (size + 5); i++)
    {
        printf("\na[%d] = %d\n", i, a[i]);
    }
    printf("\n");

    free(a);

    

    return 0;
}