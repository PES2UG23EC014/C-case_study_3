#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME_LENGTH 100
#define NUM_SUBJECTS 6
#define NUM_TESTS 3

typedef struct 
{
    float marks[NUM_TESTS];
}subject;

typedef struct 
{
    char name[MAX_NAME_LENGTH];
    subject subjects[NUM_SUBJECTS];
    float sgpa;
}student;

char calculateGrade(float marks);
float calculateSGPA(subject subjects[],int num_subjects);
void inputMarks(const char *subject,float marks[]);
void loadData(const char *filename, student **students, int *num_students);
void saveData(const char *filename, student *students, int num_students);
void searchStudent(student *students, int num_students, const char *name, const char *subject_names[]);

#endif
