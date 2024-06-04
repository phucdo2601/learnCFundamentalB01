#include <stdio.h>
#include <string.h>

void printFunc(char* c) {
    int i = 0;
    // while (c[i] != '\0')

    // while(*(c+i) != '\0')
    // {
    //     printf("%c", c[i]);
    //     i++;
    // }

    while (*c != '\0')
    {
        printf("%c", *c);
        c++;
    }
    

    printf("\n");
    
}

int main() {
    // char c[] = {'P', 'H', 'U', 'C', '\0'};

    // printf("\nSize in bytes: %d\n", sizeof(c));

    // printf("\nArray of data: %s", c);

    // int lenghtC = strlen(c);

    // printf("\n Length of string arr: %d\n", lenghtC);

    char c[20] = "Hello";

    printFunc(c);
}