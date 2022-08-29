#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Students
{
    char name[20];
    int num;
} Students;

int main(int argc, char const *argv[])
{
    int students_num, instance = 0;
    int eof = 1;
    Students students, fail_student;

    while (eof != EOF)
    {
        strcpy(fail_student.name, "");
        fail_student.num = 100;

        instance++;
        eof = scanf("%d", &students_num);

        if (eof == EOF)
        {
            break;
        }

        for (size_t i = 0; i < students_num; i++)
        {
            eof = scanf("%s %d", &students.name, &students.num);

            if (eof == EOF)
            {
                break;
            }

            if (students.num < fail_student.num)
            {
                fail_student = students;
            }
            else if (students.num == fail_student.num)
            {
                if (strcmp(students.name, fail_student.name) > 0)
                {
                    fail_student = students;
                }
            }
        }
        printf("\nInstancia %d\n", instance);
        printf("%s\n", fail_student.name);
        printf("\n");
    }

    return 0;
}
