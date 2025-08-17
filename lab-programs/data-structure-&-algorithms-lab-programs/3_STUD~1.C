#include <stdio.h>
#include <conio.h>

#define MAX_STUDENTS 100 // Predefined limit
#define NUM_SUBJECTS 3

struct Student {
    char name[50];
    int rollNumber;
    int marks[NUM_SUBJECTS];
    int totalMarks;
    float averageMarks;
};

int main() {
    int numStudents, i, j;
    struct Student students[MAX_STUDENTS];

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    for (i = 0; i < numStudents; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", students[i].name); // Corrected name input

        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);

        printf("Enter marks for %d subjects:\n", NUM_SUBJECTS);
        students[i].totalMarks = 0;
        for (j = 0; j < NUM_SUBJECTS; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &students[i].marks[j]);
            students[i].totalMarks += students[i].marks[j];
        }

        students[i].averageMarks = (float)students[i].totalMarks / NUM_SUBJECTS;
    }

    printf("\nStudent Details:\n");
    printf("--------------------------------------------------\n");
    printf("Roll No\t\tName\t\tTotal Marks\tAverage Marks\n");
    printf("--------------------------------------------------\n");

    for (i = 0; i < numStudents; i++) {
        printf("%d\t\t%s\t\t%d\t\t%.2f\n",
               students[i].rollNumber,
               students[i].name,
               students[i].totalMarks,
               students[i].averageMarks);
    }

    getch(); // Keep the output screen visible
    return 0;
}