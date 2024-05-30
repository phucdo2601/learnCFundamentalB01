#include <stdio.h>

int main()
{
    char grade;

    printf("\nEnter a letter grade: ");
    scanf("%c", &grade);

    switch (grade)
    {
    case 'A':
        printf("perfect\n");
        break;

    case 'B':
        printf("good\n");
        break;

    case 'C':
        printf("average\n");
        break;

    case 'D':
        printf("normal\n");
    default:
        break;
    }

    return 0;
}