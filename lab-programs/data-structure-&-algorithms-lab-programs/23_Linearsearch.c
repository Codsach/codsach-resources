#include <stdio.h>
#include <conio.h>

void main() {
    int a[100], search, n, c;

    clrscr();

    printf("Enter the no of elements\n");
    scanf("%d", &n);

    printf("Enter the %d integers\n", n);
    for (c = 0; c < n; c++)
        scanf("%d", &a[c]);

    printf("Enter the element to be search\n");
    scanf("%d", &search);

    for (c = 0; c < n; c++) {
        if (a[c] == search) {
            printf("%d is present at location %d", search, c + 1);
            break;
        }
    }

    if (c == n)
        printf("%d is not present in the array", search);

    getch();
}
