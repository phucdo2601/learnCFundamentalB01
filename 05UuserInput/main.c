#include <stdio.h>
#include <string.h>

int main()
{
    char name[25];
    int age;

    printf("\nWhat 's your name?: ");
    // scanf("%s", &name);
    fgets(name, 25, stdin);
    name[strlen(name) - 1] = '\0';

    printf("\nHow old are you?: ");
    scanf("%d", &age);
    // fgets(age, );

    printf("\nHello %s, how are you?\n", name);
    printf("\nYou are %d years old", age);
}