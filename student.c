#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

char *sub_names[] = {"Physics", "PSWC", "Mathematics", "Electrical", "Mechanical"};

void readStudData(const char *filename, const char *name, struct Stud *stud) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char stud_name[50];
        sscanf(line, "%49[^,],", stud_name);

        if (strcmp(stud_name, name) == 0) {
            strcpy(stud->name, stud_name);
            char *token = strtok(line, ",");
            int i = 0;

            while (token != NULL) {
                if (i > 0 && i <= MAX_SUBJECTS) {
                    stud->exam1_marks[i - 1] = atof(token);
                } else if (i > MAX_SUBJECTS) {
                    stud->exam2_marks[i - MAX_SUBJECTS - 1] = atof(token);
                }
                token = strtok(NULL, ",");
                i++;
            }
            stud->num_subs = MAX_SUBJECTS;

            printf("Student found: %s\n", stud->name);
            printf("Exam 1 marks: ");
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                printf("%.2f ", stud->exam1_marks[j]);
            }
            printf("\nExam 2 marks: ");
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                printf("%.2f ", stud->exam2_marks[j]);
            }
            printf("\n");

            break;
        }
    }

    fclose(file);
}

void listStudName(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[256];
    printf("Available students:\n");
    while (fgets(line, sizeof(line), file)) {
        char stud_name[50];
        sscanf(line, "%49[^,],", stud_name);
        printf("- %s\n", stud_name);
    }

    fclose(file);
}

float calculateAverage(float marks[], int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += marks[i];
    }
    return sum / size;
}

char gradeAssignment(float average) {
    int grade = (int)average / 10;
    switch (grade) {
        case 9:
        case 10:
            return 'S';
        case 8:
            return 'A';
        case 7:
            return 'B';
        case 6:
            return 'C';
        case 5:
            return 'D';
        case 4:
            return 'E';
        default:
            return 'F';
    }
}
