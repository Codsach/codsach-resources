#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

void sort(int arr[], int n) {
    int temp;
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

float mean(int arr[], int n) {
    int sum = 0;
    int i;
    for (i = 0; i < n; i++)
        sum += arr[i];
    return (float)sum / n;
}

float median(int arr[], int n) {
    sort(arr, n);
    if (n % 2 == 0)
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    else
        return arr[n / 2];
}

void main() {
    int n, i, resultGCD, resultLCM;
    float avg, med;
    int min, max;
    int arr[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    avg = mean(arr, n);
    med = median(arr, n);
    sort(arr, n);
    min = arr[0];
    max = arr[n - 1];

    resultGCD = arr[0];
    resultLCM = arr[0];

    for (i = 1; i < n; i++) {
        resultGCD = gcd(resultGCD, arr[i]);
        resultLCM = lcm(resultLCM, arr[i]);
    }

    printf("\nResult:\n");
    printf("Mean = %.2f\n", avg);
    printf("Median = %.2f\n", med);
    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);
    printf("GCD = %d\n", resultGCD);
    printf("LCM = %d\n", resultLCM);

    getch();
}
