#include <stdio.h>
#include <conio.h>

int binary_search(int arr[], int size, int target)
{
    int left = 0, right = size - 1;
    int mid;  // Declare mid here for Turbo C compatibility

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 15, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target, result;

    clrscr();

    printf("Enter the key element: ");
    scanf("%d", &target);

    result = binary_search(arr, size, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    getch();
}
