#include <stdio.h>
#include <string.h>

struct Employee
{
    char name[100];
    int age;
    float experience;
};

int main() {
    struct Employee emp1;

    printf("\nInput the employee information:\n");

    printf("\nInput the name of employee:\n");
    // scanf("%s", &emp1.name);
    fgets(&emp1.name, 100, stdin);

    printf("\nInput the the age of employee:\n");
    scanf("%d", &emp1.age);

    printf("\nInput the working exp year:\n");
    scanf("%f", &emp1.experience);
    
    printf("\nThe employee information details:\n");

    printf("\nEmployee of name: %s", &emp1.name);
    printf("\nEmployee of age: %d", emp1.age);
    printf("\nEmployee of name: %lf", emp1.experience);


}
