#include <stdio.h>
#include <ctype.h>

int main() {
    char unit;
    float temp;

    printf("\nIs the temperature in F or C ?: \n");
    scanf("%c", &unit);

    unit = toupper(unit);

    if (unit == 'C')
    {
        printf("The temp is currently in C.");
        printf("\nEnter the temp in CELSIUS: \n");
        scanf("%d", &temp);
        temp = (temp * 9 / 5) + 32;
        printf("\nThe temp in Farenheit: %.1f", temp);
    } else if (unit == 'F')
    {
        printf("The temp is currently in F.");
        printf("\nEnter the temp in Farenheit: \n");
        scanf("%d", &temp);
        temp = (temp * 9 / 5) + 32;
        printf("\nThe temp in CELSIUS: %.1f", temp);
    }
    else {
        printf("\n%c is not valid unit of temp of measurement", unit);
    }


    
    return 0;
}