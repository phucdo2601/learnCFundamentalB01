#include <stdio.h>
#include <conio.h>

int main()
{
    FILE *pf;

    char ch;

    pf = fopen("test-note2.txt", "r");

    if (pf == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    else
    {
        while (!feof(pf))
        {
            ch = fgetc(pf);
            printf("%c", ch);
        }
    }

    fclose(pf);

    getch();
    return 0;
}