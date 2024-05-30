
#include <stdio.h>

int main() {
/**
 *  variable = Allocated space in memory to store a value.
 *  We refer to a variable's name to access the stored value.
 *  That variable now behaves as if it was the value it contains.
 *  But we need to declare what type of data we are storing.
*/

    int x;
    x = 123;

    int y =24242;

    int age =23;

    float gpa =3.1;

    char grade = 'C'; //single character

    char name[] = "Phuc Do Ngoc"; // array of chars

    printf("Hello %s\n", name); // %s for string;
    printf("You are %d years old\n", age); // %d for int number

    printf("Your average grade is %c\n", grade); // %c for character

    printf("Your gpa is %f", gpa); // %f for float type



    return 0;
}