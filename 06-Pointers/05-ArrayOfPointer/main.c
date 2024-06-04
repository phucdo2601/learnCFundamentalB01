#include <stdio.h>

int main() {
    /**
     * First learn basic Array with pointer: In this case: if user print value of array, the result will be displayed the value of the first pos of arr
     * 
    */

    int A[] = {2,3,4,5,6,9,7,8,0,23,13,34,45};
    // printf("\nValue of Array A: %d", *A);
    // printf("\nAddress of Array A: %d", &A);
    // printf("\nValue of Array A on index 0: %d", A[0]);
    // printf("\nAddress of Array A on index 0: %d", &A[0]);

    int *p1 = A;

    for (int i = 0; i < 5; i++)
    {
        /* code */
        printf("\nAddress of ele in %d: %d",i, &A[i]);
        printf("\nValue of ele in %d: %d",i, A[i]);
        printf("\nAddress of ele in %d + 1: %d",i, A + i);
        printf("\nValue of ele in %d + 1: %d",i, *(A + i));

    }
    
}