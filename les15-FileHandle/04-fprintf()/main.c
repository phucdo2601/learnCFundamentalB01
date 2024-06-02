#include <stdio.h>
#include <conio.h>

int main()
{
    FILE *pf;
    char username[100];
    int age;

    /**
     * fprintf(file_pointer, "format specifier", list of variables)
     */

    printf("\nEnter the username:\n");
    scanf("%s", username);
    printf("\nEnter the age:\n");
    scanf("%d", &age);

    pf = fopen("test-note2.txt", "a");

    if (pf == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    else
    {
        fprintf(pf, "%s\t%d\n", username, age);
        printf("\nData has written successfully\n");
    }

    fclose(pf);

    getch();
    return 0;
}
