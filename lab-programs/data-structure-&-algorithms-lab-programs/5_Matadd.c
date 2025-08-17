#include <stdio.h>
#include <conio.h>

void main() {
    int a[10][10], b[10][10], c[10][10];
    int i, j, c1, r1, c2, r2;

    clrscr();

    printf("Enter the number of rows of first matrix:\n");
    scanf("%d", &r1);

    printf("Enter the number of columns of first matrix:\n");
    scanf("%d", &c1);

    printf("Enter the elements of First matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the number of rows of second matrix:\n");
    scanf("%d", &r2);

    printf("Enter the number of columns of second matrix:\n");
    scanf("%d", &c2);

    // Check if matrix dimensions are the same
    if (r1 != r2 || c1 != c2) {
        printf("Matrix addition not possible. Dimensions do not match.\n");
        getch();
        return;
    }

    printf("Enter the elements of Second matrix:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    printf("Addition of two matrices:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            c[i][j] = a[i][j] + b[i][j];
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    getch();
}
