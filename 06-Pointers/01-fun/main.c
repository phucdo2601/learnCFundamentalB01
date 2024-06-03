#include <stdio.h>

int main()
{
    int a;
    a = 10;
    int *p;
    p = &a; // &a = address of a
    printf("%d\n", p);
    printf("%d\n", *p); // *p = print value of a
    printf("%d\n", &a);

    printf("The value of a before re-assign pointer:%d\n", a);
    *p = 12;
    printf("The value of a after re-assign pointer:%d\n", a);

    int b = 20;
    p = &b;
    *p = b;
    printf("The value of p after re-assign pointer:%d\n", *p);

    int *p2 = &a;

    printf("\nValue of p2: %d\n", *p2);
    printf("\nAddress of p2: %d\n", p2);
    printf("\nAddress of p2 + 1: %d\n", p2 + 1);
    printf("\nValue of p2 + 1: %d\n", *(p2 + 1));

    return 0;
}