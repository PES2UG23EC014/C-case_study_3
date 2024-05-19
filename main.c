#include <stdio.h>
#include "student.h"

int main() {
    char filename[] = "studinfo.csv";
    char stud_name[50];
    struct Stud stud;

    listStudName(filename);
    printf("Enter student name: ");
    scanf("%s", stud_name);

    readStudData(filename, stud_name, &stud);

    float avg1 = calculateAverage(stud.exam1_marks, stud.num_subs);
    float avg2 = calculateAverage(stud.exam2_marks, stud.num_subs);

    char grade1 = gradeAssignment(avg1);
    char grade2 = gradeAssignment(avg2);

    printf("\n===== Grade Card =====\n");
    printf("Name: %s\n\n", stud.name);

    printf("Exam 1 Marks:\n\n");
    for (int i = 0; i < stud.num_subs; i++) {
        printf("%s: %.2f\n", sub_names[i], stud.exam1_marks[i]);
    }
    printf("\nExam 1 Average: %.2f\n\n", avg1);
    printf("Exam 1 Grade: %c\n\n", grade1);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Exam 2 Marks:\n\n");
    for (int i = 0; i < stud.num_subs; i++) {
        printf("%s: %.2f\n", sub_names[i], stud.exam2_marks[i]);
    }
    printf("\nExam 2 Average: %.2f\n", avg2);
    printf("Exam 2 Grade: %c\n", grade2);

    return 0;
}
