#include <stdio.h>
#include <string.h>
#include <stdlib.h> // the lib for many funcs for managing memory

// struct Student {
//     char name[50];
//     char id[10];
//     int age;
//     int grades[5];
// };

/**
 * Using typedef with struct for saving time for declaring with struct about not-declearing type struct when user declares struct for using.
*/

typedef struct {
    char name[50];
    char id[10];
    int age;
    int grades[5];
} Student;

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int *array;
} Data;

/**
 * Fuction definition
*/
void print_student(Student student);
void print_points(Point points[], int pointSize);


void print_student(Student st1) {
    printf("\nName: %s", st1.name);
    printf("\nID: %d", st1.id);

    printf("\nAge: %d", st1.age);

    int list_length_grade = sizeof(st1.grades) / sizeof(st1.grades[0]);


    printf("\nSize of Grades Arr: %d", list_length_grade);

    for (int i = 0; i < list_length_grade; i++)
    {
        printf("\nGrade[%d]: %d", i+1, st1.grades[i] );
    }
}

void print_points(Point points[], int pointSize) {

    for (int i = 0; i < pointSize; i++)
    {
        printf("\np1.x[%d] = %d", i + 1, points[i].x);
        printf("\np1.y[%d] = %d", i + 1, points[i].y);
    }
}

int main() {
    // struct Student st1;
    Student st1;

    st1.age = 24;
    st1.grades[0] = 7;
    st1.grades[1] = 8;
    st1.grades[2] = 9;
    st1.grades[3] = 6;
    st1.grades[4] = 8;

    strcpy(st1.name, "Phuc Do");
    strcpy(st1.id, "123");

    print_student(st1);

    Point p1 = {
        5, 10
    };
    Point p2 = {
        .y = 9,
        .x = 6
        
    };

    p1 = p2;

    printf("\np1.x = %d", p1.x);
    printf("\np1.y = %d", p1.y);

    Point points[10];
    int pointSize = sizeof(points) / sizeof(points[0]);

    for (int i = 0; i < pointSize; i++)
    {
        points[i].x = i;
        points[i].y = 10 - i;
    }
    
    print_points(points, pointSize);

    Data x;
    Data y;

    x.array = malloc(sizeof(int) * 5);
    y.array = malloc(sizeof(int) * 5);

    x.array[0] = 1;
    x.array[1] = 2;
    x.array[2] = 3;
    x.array[3] = 4;
    x.array[4] = 5;

    y.array[0] = 9;
    y.array[1] = 9;
    y.array[2] = 9;
    y.array[3] = 9;
    y.array[4] = 9;

    x = y;

for (int i = 0; i < 5; i++)
    {
        printf("\nx.array[%d] = %d", i, x.array[i]);
    }
    
    x.array[0] = 10;

for (int i = 0; i < 5; i++)
    {
        printf("\nx.array[%d] = %d", i, x.array[i]);
    }
    
    return 0;
}
