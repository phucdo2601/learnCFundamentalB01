#include <stdio.h>

int main()
{
    int a = 1025;
    int *p;
    p = &a;

    printf(" \nSize of integer is %d bytes \n", sizeof(int));
    printf("\nAddress of var pointer p = %d, value of pointer p = %d\n", p, *p);
    // printf("\nAddress of var pointer p + 1 = %d, value of pointer p + 1 = %d\n", p + 1, *(p + 1));

    // char *p0;
    // p0 = (char *)p; // typecasting

    // printf("\nSize of char is %d bytes \n", sizeof(char));

    // printf("\nAddress of var pointer p0 = %d, value of pointer p0 = %d\n", p0, *p0);

    /**
     * void pointer - Generic pointer
     */
    void *p1;

    p1 = p;
    printf("\nAddress of var pointer p1 = %d", p1);
    printf("\nAddress of var pointer p1 + 1= %d", p1 + 1);

    return 0;
}