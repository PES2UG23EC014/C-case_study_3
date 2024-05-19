#ifndef STUDENT_H
#define STUDENT_H

#define MAX_SUBJECTS 5

struct Stud {
    char name[50];
    float exam1_marks[MAX_SUBJECTS];
    float exam2_marks[MAX_SUBJECTS];
    int num_subs;
};

extern char *sub_names[];

void readStudData(const char *filename, const char *name, struct Stud *stud);
void listStudName(const char *filename);
float calculateAverage(float marks[], int size);
char gradeAssignment(float average);

#endif 
