#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct {
//     char name[50];
//     int age;
// } Person;

struct Person {
    char name[50];
    int age;
} ;

int main() {
//     /**
//      * Allocate memory for a struct Person with using typedef in struct
//     */
//    Person *personPtr = (Person *) malloc(sizeof(Person));

    /**
     * Allocate memory for a struct Person
    */
    struct Person *personPtr = (struct Person *)malloc(sizeof(struct Person));

   // Check if memory allocation was successful
    if (personPtr == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
    }
    
    // Assigning values using arrow operator
    strcpy(personPtr->name, "PhucDn");
    personPtr->age = 25;

    // Accessing values using arrow operator
    printf("\nName %s, age: %d\n", personPtr->name, personPtr->age);

    /**
     * Free allocated memory
    */
    free(personPtr);

    return 0;
}