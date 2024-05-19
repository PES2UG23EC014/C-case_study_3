/*main.c: The Main File*/

#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main()
{
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    struct Student *students = (struct Student *)malloc(num_students * sizeof(struct Student));

    for (int i = 0; i < num_students; i++) 
    {
        printf("\nStudent %d:\n", i + 1);
        inputStudentData(&students[i]);
        generateGradeCard(&students[i]);
    }

    free(students);
    return 0;
}
