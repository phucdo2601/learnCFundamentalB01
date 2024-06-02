#include <stdio.h>
#include <conio.h>

int main()
{
    FILE *pf;
    char data[1000];
    char name[1000];
    int num1;

    pf = fopen("test-note2.txt", "r");

    if (pf == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    else
    {
        fscanf(pf, "%s\t%d", data, &num1);
        printf("%s\t%d", data, num1);
    }

    fclose(pf);

    getch();

    return 0;
}