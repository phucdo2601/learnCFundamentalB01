#include <stdio.h>

void Increment(int a) {
    a = a + 1;

    printf("\nAddress of variable a in increment = %d\n", &a);
}

int main() {
    int a;

    a = 10;

    Increment(a);

    printf("\nAddress of variable a in main = %d\n", &a);


    // printf("\n Value of var a = %d", a);

    return 0;
}