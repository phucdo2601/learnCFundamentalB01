#include <stdio.h>
#include <string.h>

void printFunc(const char* c) {
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
    // char c[20] = "Hello"; // string gets stored in the space for array
    char *c = "Hello"; // string gets stored as complie time constant
    // c[0] = 'T';
    printFunc(c);
}