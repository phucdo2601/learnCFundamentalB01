#include <stdio.h>
#include <conio.h>

int main()
{
    FILE *pf;
    char data[100];

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
            fgets(data, 100, pf);
            printf("\nThe characters readed were %s\n", data);
        }
    }

    fclose(pf);
    getch();
    return 0;
}
