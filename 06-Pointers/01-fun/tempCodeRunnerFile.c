#include <stdio.h>

int main()
{
    int a;
    int *p;
    p = &a; // &a = address of a
    printf("%d\n", p);
}