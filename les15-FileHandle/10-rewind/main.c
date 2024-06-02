#include <stdio.h>
#include <conio.h>

int main()
{
    FILE *fp;

    fp = fopen("test-note2.txt", "r");

    while (!feof(fp))
    {
        putchar(fgetc(fp));
    }

    rewind(fp);
    printf("\n");

    while (!feof(fp))
    {
        putchar(fgetc(fp));
    }

    getch();
    return 0;
}
