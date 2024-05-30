#include <stdio.h>
#include <math.h>

int main()
{
    double a;
    double b;
    double c;

    printf("Enter side A:\t");
    scanf("%lf", &a);

    printf("Enter side B:\t");
    scanf("%lf", &b);

    c = sqrt(pow(a, 2) + pow(b, 2));

    printf("Side c: %lf", c);

    return 0;
}