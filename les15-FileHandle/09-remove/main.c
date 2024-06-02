#include <stdio.h>
#include <conio.h>

int main()
{
    int status;

    status = remove("test-note2.txt");
    printf("%d\n", status);

    if (status == 0)
    {
        puts("file deleted successfully\n");
    }
    else
    {
        puts("file not deleted\n");
    }

    getch();
    return 0;
}