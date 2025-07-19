#include <stdio.h>
#include <conio.h>

void main() {
    float basicpay, hra, ta, it, grosssalary, netsalary;

    printf("Enter the basic pay\n");
    scanf("%f", &basicpay);

    printf("Enter the HRA\n");
    scanf("%f", &hra);

    printf("Enter the TA\n");
    scanf("%f", &ta);  // FIXED: Added &

    printf("Enter IT deduction\n");
    scanf("%f", &it);

    grosssalary = basicpay + hra + ta;
    netsalary = grosssalary - it;

    printf("The gross salary & net salary is %.2f & %.2f", grosssalary, netsalary);

    getch();
}
