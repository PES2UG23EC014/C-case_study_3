#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main() 
{
    int num_students;
    student *students;

    loadData("students.csv",&students,&num_students);
    printf("Loaded %d students.\n",num_students);

    if (students==NULL) 
    {
        printf("No entries. Starting with an empty list.\n");
        num_students=0;
        students=malloc(0);
    } 

    const char *subject_names[NUM_SUBJECTS]={"PSWC","Physics","Maths","Electrical","Mechanical","EVS"};

    //input new data
    int add_students=1;
    while(add_students) 
    {
        students=realloc(students,(num_students+1)*sizeof(student));
        if(students==NULL) 
        {
            perror("Failed to allocate memory");
            return 1;
        }

        printf("\nEnter name of student %d: ",num_students+1);
        scanf("%s",students[num_students].name);

        printf("Enter details for student %d (3 tests each out of 100):\n",num_students+1);
        for(int j=0; j<NUM_SUBJECTS; j++) 
        {
            inputMarks(subject_names[j],students[num_students].subjects[j].marks);
        }

        students[num_students].sgpa=calculateSGPA(students[num_students].subjects,NUM_SUBJECTS);
        printf("\nGrade card for %s:\n", students[num_students].name);
        for (int j = 0; j < NUM_SUBJECTS; j++) 
        {
            printf("\tSubject-%s: ", subject_names[j]);
            for (int k = 0; k < NUM_TESTS; k++) 
            {
                printf("\n\t\tTest %d - Grade %c ", k + 1, calculateGrade(students[num_students].subjects[j].marks[k]));
            }
            printf("\n");
        }
        printf("\nSGPA for %s: %.2f\n", students[num_students].name, students[num_students].sgpa);


        num_students++;
        printf("Press 0 to stop, 1 to add more students: ");
        scanf("%d", &add_students);
    }

    //sgpa
    for(int i=0; i<num_students; i++) 
    {
        students[i].sgpa=calculateSGPA(students[i].subjects,NUM_SUBJECTS);
    }

    for (int i = num_students - add_students; i < num_students; i++) 
    {
        printf("\nGrade card for %s:\n", students[i].name);
        for (int j = 0; j < NUM_SUBJECTS; j++) 
        {
            printf("\tSubject-%s: ", subject_names[j]);
            for (int k = 0; k < NUM_TESTS; k++) 
            {
                printf("\n\t\tTest %d - Grade %c ", k + 1, calculateGrade(students[i].subjects[j].marks[k]));
            }
            printf("\n");
        }
        printf("\nSGPA for %s: %.2f\n", students[i].name, students[i].sgpa);
    }

saveData("students.csv",students,num_students);             

    char choice;
    printf("Do you want to search for a student? (Y/N): ");
    scanf(" %c",&choice);
    if(choice=='Y' || choice=='y') 
    {
        char search_name[MAX_NAME_LENGTH];
        printf("Enter name of student to search: ");
        scanf("%s",search_name);
        searchStudent(students,num_students,search_name,subject_names);
    }

    free(students);                                             

    return 0;
}
