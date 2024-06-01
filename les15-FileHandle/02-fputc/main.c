#include <stdio.h>
#include <conio.h>

int main()
{
    FILE *FPointer; // Correct: file is a pointer to a FILE structure

    char data[25] = "Hello Phucdn test 1234";

    int length = strlen(data);
    int counter;

    FPointer = fopen("test-note2.txt", "a"); // Correct: fopen returns a pointer to a FILE structure
    if (FPointer == NULL)
    {
        printf("Error opening file\n");
    }
    else
    {
        for (counter = 0; counter < length; counter++)
        {
            printf("Writing the character %c \n", data[counter]);
            fputc(data[counter], FPointer);
        }

        printf("data written to the file successfully\n");
    }
    fclose(FPointer); // Correct: fclose takes a pointer to a FILE structure
    getch();
    return 0;
}