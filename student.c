/*student.c: The Functions File*/



#include <stdio.h>
#include "student.h"


char *subject_names[] = {"Physics", "PSWC", "Mathematics", "Electrical", "Mechanical"};

void inputStudentData(struct Student *student) 
{
    printf("Enter student name: ");
    scanf("%s", student->name);

    printf("Enter the number of subjects for Exam 1: ");
    scanf("%d", &student->num_subjects);

    printf("Enter marks for Exam 1:\n");
    for (int i = 0; i < student->num_subjects; i++) 
    {
        printf("%s (Exam 1): ", subject_names[i]);
        scanf("%f", &student->exam1_marks[i]);
    }

    printf("Enter the number of subjects for Exam 2: ");
    scanf("%d", &student->num_subjects_exam2);

    printf("Enter marks for Exam 2:\n");
    for (int i = 0; i < student->num_subjects_exam2; i++) 
    {
        printf("%s (Exam 2): ", subject_names[i]);
        scanf("%f", &student->exam2_marks[i]);
    }
}

float calculateAverage(float *marks, int size) 
{
    float sum = 0.0;
    for (int i = 0; i < size; i++) 
    {
        sum += marks[i];
    }
    return sum / size;
}

char gradeAssignment(float avg_marks)  
{
    char grade;
    switch ((int)avg_marks / 10) {
        case 10:
        case 9:
            grade = 'S';
            break;
        case 8:
            grade = 'A';
            break;
        case 7:
            grade = 'B';
            break;
        case 6:
            grade = 'C';
            break;
        case 5:
            grade = 'D';
            break;
        case 4:
            grade = 'E';
            break;
        default:
            grade = 'F';
    }
    return grade;
}

void generateGradeCard(struct Student *student)
    {
    printf("\n===== Grade Card =====\n");
    printf("Name: %s\n", student->name);

    float avg1 = calculateAverage(student->exam1_marks, student->num_subjects);
    float avg2 = calculateAverage(student->exam2_marks, student->num_subjects);

    printf("Average Marks (Exam 1): %.2f\n", avg1);
    printf("Grade (Exam 1): %c\n", gradeAssignment(avg1));

    printf("Average Marks (Exam 2): %.2f\n", avg2);
    printf("Grade (Exam 2): %c\n", gradeAssignment(avg2));
}
