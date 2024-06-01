#include <stdio.h>
#include <conio.h>

int main()
{
    FILE *FPointer;

    FPointer = fopen("test-note2.txt", "a");
    if (FPointer == NULL)
    {
        printf("\nUnable to read the file.");
    }
    else
    {
        printf("\nFile opened successfully.");
        fclose(FPointer);
    }

    getch();

    return 0;
}