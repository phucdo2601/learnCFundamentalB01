#include <stdio.h>
#include <stdlib.h>

/**
 * Define struct with typedef
 */
typedef struct
{
    int rno;
    char name[30];
    // int age;
    // char gradeChar;
    struct Subject
    {
        int scode;
        char sname[30];
        double mark;
    } sub[3];
    double total;
    double per;
} Student;

void create()
{
    Student *st;
    FILE *fp;
    int numSt;
    int i;
    int j;

    printf("\nEnter the number of students you want :\n");
    scanf("%d", &numSt);

    st = (Student *)calloc(numSt, sizeof(Student));
    fp = fopen("myStudents.txt", "w");

    for (i = 0; i < numSt; i++)
    {
        st[i].total = 0;
        st[i].per = 0;
        printf("\nEnter RollNo:\n");
        scanf("%d", &st[i]);
        fflush(stdin);
        printf("\nEnter Name:\n");
        scanf("%[^\n]s", st[i].name);

        for (j = 0; j < 3; j++)
        {
            printf("\nEnter Marks of Subject%d: ", j + 1);
            scanf("%lf", &st[i].sub[j].mark);
            st[i].total += st[i].sub[j].mark;
        }
        st[i].per = st[i].total / 3.0;
        fwrite(&st[i], sizeof(Student), 1, fp);
    }
    fclose(fp);
}

void display()
{
    Student st;
    FILE *fp;
    fp = fopen("myStudents.txt", "r");

    while (fread(&st, sizeof(Student), 1, fp))
    {
        printf("\n%-5d%-20s", st.rno, st.name);
        for (int j = 0; j < 3; j++)
        {
            printf("%10.2lf", st.sub[j].mark);
        }
        printf("%7.2lf%7.2lf", st.total, st.per);
    }
    fclose(fp);
}

void append()
{
    Student *st;
    FILE *fp;
    int numSt;
    int i;
    int j;

    printf("\nEnter the number of students you want :\n");
    scanf("%d", &numSt);

    st = (Student *)calloc(numSt, sizeof(Student));
    fp = fopen("myStudents.txt", "a");

    for (i = 0; i < numSt; i++)
    {
        st[i].total = 0;
        st[i].per = 0;
        printf("\nEnter RollNo:\n");
        scanf("%d", &st[i]);
        fflush(stdin);
        printf("\nEnter Name:\n");
        scanf("%[^\n]s", st[i].name);

        for (j = 0; j < 3; j++)
        {
            printf("\nEnter Marks of Subject%d: ", j + 1);
            scanf("%lf", &st[i].sub[j].mark);
            st[i].total += st[i].sub[j].mark;
        }
        st[i].per = st[i].total / 3.0;
        fwrite(&st[i], sizeof(Student), 1, fp);
    }
    fclose(fp);
}

void noofrec()
{
    Student st;
    FILE *fp;
    fp = fopen("myStudents.txt", "r");
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(Student);

    printf("\n\nNO OF RECORD = %d", n);
    fclose(fp);
}

void search()
{
    Student st;
    FILE *fp;
    int j;
    int rnoSearch;
    int foundSearch = 0;
    fp = fopen("myStudents.txt", "r");
    printf("\nEnter rollno to search: \n");
    scanf("%d", &rnoSearch);

    while (fread(&st, sizeof(Student), 1, fp))
    {
        if (st.rno == rnoSearch)
        {
            foundSearch = 1;
            printf("\n%-5d%-20s", st.rno, st.name);

            for (j = 0; j < 3; j++)
            {
                printf("%10.2lf", st.sub[j].mark);
            }

            printf("%5lf%10.2lf", st.total, st.per);
        }
    }

    if (!foundSearch)
    {
        printf("\nRecord not found!");
    }
}

void update() {
    Student st;
    FILE *fp;
    FILE *fp1;
    int j;
    int rnoSearch;
    int foundUpdate = 0;
    fp = fopen("myStudents.txt", "r");
    fp1 = fopen("temp.txt", "w");
    printf("\nEnter rollno to update: \n");
    scanf("%d", &rnoSearch);

    while (fread(&st, sizeof(Student), 1, fp))
    {
        if (st.rno == rnoSearch)
        {
            foundUpdate = 1;
            fflush(stdin);

            printf("\nEnter New Name:\n");
            scanf("%[^\n]s", st.name);

            for (j = 0; j < 3; j++)
            {
                printf("\nEnter New Marks of Subject%d: ", j + 1);
                scanf("%lf", &st.sub[j].mark);
                st.total += st.sub[j].mark;
            }
            st.per = st.total / 3.0;
        }
        fwrite(&st, sizeof(Student), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);

    if (foundUpdate)
    {
        fp1 = fopen("temp.txt", "r");
        fp = fopen("myStudents.txt", "w");

        while (fread(&st, sizeof(Student), 1, fp1))
        {
            fwrite(&st, sizeof(Student), 1, fp);
        }
        

        fclose(fp);
        fclose(fp1);
    } else {
        printf("\nRecord not found!");
    }
}

int main()
{
    int ch;

    do
    {
        /* code */
        printf("\nStudent Management System: ");
        printf("\n1.CREATE");
        printf("\n2.DISPLAY");
        printf("\n3.APPEND");
        printf("\n4.NO OF RECORDS");
        printf("\n5.SEARCH");
        printf("\n6.UPDATE");
        printf("\n0.EXIT");

        printf("\nEnter your choice: ");

        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;

        case 2:
            display();
            break;

        case 3:
            append();
            break;

        case 4:
            noofrec();
            break;

        case 5:
            search();
            break;
        case 6:
            update();
            break;
        }
    } while (ch != 0);

    return 0;
}