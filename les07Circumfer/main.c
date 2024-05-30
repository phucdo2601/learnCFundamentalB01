#include <stdio.h>
#include <math.h>
int main()
{
    const double PI = 3.14159;
    double radius;
    double circumference;
    double area;

    printf("\nEnter radius of a circle: ");
    scanf("%lf", &radius);

    circumference = 2 * PI * radius;
    printf("\nCircumference of the circle is: %lf", circumference);

    area = PI * pow(radius, 2);
    printf("\nArea of the circle is: %lf", area);

    return 0;
}