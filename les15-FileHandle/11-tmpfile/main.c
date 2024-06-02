#include <stdio.h>
#include <conio.h>

int main()
{
    FILE *tmp;
    char data[] = "hello world!";
    int length = strlen(data);
    int counter = -1;

    tmp = tmpfile();

    if (tmp != NULL)
    {
        puts("\nTemp file created\n");
        while (++counter < length)
        {
            fputc(data[counter], tmp);
        }

        rewind(tmp);

        while (!feof(tmp))
        {
            putchar(fgetc(tmp));
        }
    }
    else
    {
        puts("\nTemp file not created\n");
    }

    getch();
    return 0;
}