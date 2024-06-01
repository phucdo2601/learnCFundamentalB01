#include <stdio.h>
#include <conio.h>

int main()
{
    FILE *pf;
    char input[25];

    pf = fopen("test-note2.txt", "a+");

    if (pf == NULL)
    {
        printf("Unable to open the file\n");
    }
    else
    {
        printf("\nEnter a string to write to the file:\n");
        gets(input);
        fputs(input, pf);
        printf("\nData has written successfully\n");
        fclose(pf);
    }

    getchar();
    return 0;
}