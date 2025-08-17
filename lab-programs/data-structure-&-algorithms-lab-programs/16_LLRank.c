#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct student {
    int id;
    char name[50];
    int totalMarks;
};

void sortByMarks(struct student s[], int n) {
    int i, j;
    struct student temp;
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (s[i].totalMarks < s[j].totalMarks) {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

void displayRankList(struct student s[], int n) {
    int i;
    printf("\n---Student Rank List---\n");
    printf("Rank\tId\tName\t\tTotal Marks\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%-15s\t%d\n", i + 1, s[i].id, s[i].name, s[i].totalMarks);
    }
}

int main() {
    struct student students[MAX];
    int n, i;

    clrscr();  // Turbo C screen clear

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\n Enter details for student %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf("%s", students[i].name);  // No & needed for arrays

        printf("Total Marks: ");
        scanf("%d", &students[i].totalMarks);
    }

    sortByMarks(students, n);
    displayRankList(students, n);

    getch(); // Wait for key press in Turbo C
    return 0;
}
