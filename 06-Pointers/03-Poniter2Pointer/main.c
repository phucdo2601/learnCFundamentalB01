#include <stdio.h>

int main() {
    int x = 10;
    int *p1 = &x;
    *p1 = 20;
    int **p2 = &p1;
    int ***p3 = &p2;

    printf("\nAddress of pointer *p1:%d\n", &p1);
    printf("\nValue of pointer *p1:%d\n", *p1);
    printf("\nAddress of pointer *p2:%d\n", *p2);
    printf("\nValue of pointer *p2:%d\n", *(*p2));
    printf("\nAddress of pointer *p3:%d\n", *(*p3));
    printf("\nValue of pointer *p3:%d\n", *(*(*p3)));

    ***p3 = 10;
    printf("\nValue of x after modifying pointer ***p3 with value %d: %d\n", *(*(*p3)),x);

    **p2 = *p1 + 2;

    printf("\nValue of of x after modifying pointer **p2 with adding 2: %d\n", x);
    printf("\nAddress of of x after modifying pointer **p2 with adding 2: %d\n", &x);

    return 0;
}