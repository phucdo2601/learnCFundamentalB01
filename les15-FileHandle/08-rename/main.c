#include <stdio.h>
#include <conio.h>

int main()
{

    if (rename("test-note2.txt", "test-rename-file.txt") == 0)
    {
        puts("file renamed successfully!\n");
    }
    else
    {
        puts("file renamed error!\n");
    }

    getch();
    return 0;
}