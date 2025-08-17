#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main() {
    int a[10][10], b[10][10], c[10][10];
    int i, j, k, r1, c1, r2, c2;

    clrscr();

    printf("Enter the number of rows of First matrix: ");
    scanf("%d", &r1);

    printf("Enter the number of columns of First matrix: ");
    scanf("%d", &c1);

    printf("Enter the elements of First matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the number of rows of Second matrix: ");
    scanf("%d", &r2);

    printf("Enter the number of columns of Second matrix: ");
    scanf("%d", &c2);

    if (c1 != r2) {
        printf("\nError: Matrix multiplication not possible.\n");
        getch();  // Do not use return inside void main
        return;   // or you can use: exit(0);
    }

    printf("Enter the elements of Second matrix:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nMultiplication Result:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            c[i][j] = 0;
            for (k = 0; k < c1; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    getch();
}
