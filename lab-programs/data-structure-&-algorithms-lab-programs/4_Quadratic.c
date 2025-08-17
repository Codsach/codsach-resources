#include <stdio.h>
#include <conio.h>
#include <math.h>

void main() {
    double a, b, c, d, r1, r2, real, imaginary;
    clrscr();

    printf("Enter the co-efficients\n");
    scanf("%lf%lf%lf", &a, &b, &c);

    d = b * b - 4 * a * c;

    if (d > 0) {
        r1 = (-b + sqrt(d)) / (2 * a);
        r2 = (-b - sqrt(d)) / (2 * a);
        printf("r1 = %.2lf and r2 = %.2lf", r1, r2);
    } else if (d == 0) {
        r1 = r2 = -b / (2 * a);
        printf("r1 = r2 = %.2lf", r1);
    } else {
        real = -b / (2 * a);
        imaginary = sqrt(-d) / (2 * a);
        printf("r1 = %.2lf + %.2lfi and r2 = %.2lf - %.2lfi", real, imaginary, real, imaginary);
    }

    getch();
}
