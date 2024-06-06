#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
            st.total = 0;
            st.per = 0;
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

void delete_rec() {
    Student st;
    FILE *fp;
    FILE *fp1;
    int j;
    int rnoSearch;
    int foundUpdate = 0;
    fp = fopen("myStudents.txt", "r");
    fp1 = fopen("temp.txt", "w");
    printf("\nEnter rollno to delete: \n");
    scanf("%d", &rnoSearch);

    while (fread(&st, sizeof(Student), 1, fp))
    {
        if (st.rno == rnoSearch)
        {
            foundUpdate = 1;
        } else {
            fwrite(&st, sizeof(Student), 1, fp1);
        }
        
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

void sort_total_on_screen() {
    Student *st1;
    Student st2;
    FILE *fp;
    fp = fopen("myStudents.txt", "r");
    fseek(fp, 0, SEEK_END);

    int n = ftell(fp) / sizeof(Student);
    rewind(fp);
    st1 = (Student*) calloc(n, sizeof(Student));

    for (int i = 0; i < n; i++)
    {
        fread(&st1[i], sizeof(Student), 1, fp);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (st1[i].total  < st1[j].total)
            {
                st2 = st1[i];
                st1[i] = st1[j];
                st1[j] = st2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("\n%-5d%-20s", st1[i].rno, st1[i].name);
        for (int j = 0; j < 3; j++)
        {
            printf("%10.2lf", st1[i].sub[j].mark);
        }
        printf("%7.2lf%7.2lf", st1[i].total, st1[i].per);
    }
    fclose(fp);
}

void sort_total_in_file() {
    Student *st1;
    Student st2;
    FILE *fp;
    fp = fopen("myStudents.txt", "r");
    fseek(fp, 0, SEEK_END);

    int n = ftell(fp) / sizeof(Student);
    rewind(fp);
    st1 = (Student*) calloc(n, sizeof(Student));

    for (int i = 0; i < n; i++)
    {
        fread(&st1[i], sizeof(Student), 1, fp);
    }
    fclose(fp);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (st1[i].total  < st1[j].total)
            {
                st2 = st1[i];
                st1[i] = st1[j];
                st1[j] = st2;
            }
        }
    }

    fp = fopen("myStudents.txt", "w");

    for (int i = 0; i < n; i++)
    {
        printf("\n%-5d%-20s", st1[i].rno, st1[i].name);
        for (int j = 0; j < 3; j++)
        {
            printf("%10.2lf", st1[i].sub[j].mark);
        }
        printf("%7.2lf%7.2lf", st1[i].total, st1[i].per);
        fwrite(&st1[i], sizeof(Student), 1, fp);
    }
    fclose(fp);
}

void sort_by_name_on_screen() {
    Student *st1;
    Student st2;
    FILE *fp;
    fp = fopen("myStudents.txt", "r");
    fseek(fp, 0, SEEK_END);

    int n = ftell(fp) / sizeof(Student);
    rewind(fp);
    st1 = (Student*) calloc(n, sizeof(Student));

    for (int i = 0; i < n; i++)
    {
        fread(&st1[i], sizeof(Student), 1, fp);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (strcmp(st1[i].name, st1[j].name) > 0)
            {
                st2 = st1[i];
                st1[i] = st1[j];
                st1[j] = st2;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("\n%-5d%-20s", st1[i].rno, st1[i].name);
        for (int j = 0; j < 3; j++)
        {
            printf("%10.2lf", st1[i].sub[j].mark);
        }
        printf("%7.2lf%7.2lf", st1[i].total, st1[i].per);
    }
    fclose(fp);
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
        printf("\n7.DELETE");
        printf("\n8.SORT BY TOTAL DESC - ON SCREEN");
        printf("\n9.SORT BY TOTAL DESC - IN FILE");
        printf("\n10.SORT BY NAME - ON SCREEN");
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

        case 7:
            delete_rec();
            break;

        case 8:
            sort_total_on_screen();
            break;

        case 9:
            sort_total_in_file();
            break;

        case 10:
            sort_by_name_on_screen();
            break;
        }
    } while (ch != 0);

    return 0;
}