#include <stdio.h>
#include <stdbool.h>

int main()
{

    // LOGICAL operators OR

    float temp = 25;

    if (temp <= 0 || temp >= 30)
    {
        printf("The weather is bad!\n");
    }
    else
    {
        printf("The weather is good!\n");
    }
}
