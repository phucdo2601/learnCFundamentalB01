#include <stdio.h>

int main()
{
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age >= 18)
    {
        printf("You are now signed up.\n");
    }
    else if (age < 18 && age > 15)
    {
        printf("You are not enought for debating\n");
    }
    else
    {
        printf("You are so young\n");
    }

    return 0;
}