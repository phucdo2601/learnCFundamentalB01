#include <stdio.h>

int SumOfEles(int a[], int size) {
    int i, sum = 0;

    for(i = 0; i < size; i++ ) {
        sum += a[i];
    }

    return sum;

}

int main() {
    int a[] = {1,2,3,4,5};

    int size = sizeof(a) / sizeof(a[0]);

    int total = SumOfEles(a, size);
    printf("\nSum  of eles: a = %d\n", total);
    printf("\nMain -size of A = %d, side of a[0] = %d\n", sizeof(a), sizeof(a[0]));

}