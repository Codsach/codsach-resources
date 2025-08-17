#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // Required for clrscr() and getch()

int main()
{
    int *arr1, *arr2, *arr3;
    int n, i, newsize;

    clrscr();  // Clears the screen

    // malloc
    printf("Enter the number of elements for malloc: ");
    scanf("%d", &n);

    arr1 = (int *)malloc(n * sizeof(int));
    if (arr1 == NULL)
    {
        printf("Memory allocation failed for malloc");
        getch(); return 1;
    }

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Malloc allocated array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n\n");

    // calloc
    printf("Enter the number of elements for calloc: ");
    scanf("%d", &n);

    arr2 = (int *)calloc(n, sizeof(int));
    if (arr2 == NULL)
    {
        printf("Memory allocation failed for calloc\n");
        getch(); return 1;
    }

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }

    printf("Calloc allocated array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n\n");

    // realloc
    printf("Enter the new size for realloc: ");
    scanf("%d", &newsize);

    arr3 = (int *)realloc(arr1, newsize * sizeof(int));
    if (arr3 == NULL)
    {
        printf("Memory allocation failed\n");
        getch(); return 1;
    }

    printf("Enter %d elements: ", newsize);
    for (i = 0; i < newsize; i++)
    {
        scanf("%d", &arr3[i]);
    }

    printf("Reallocated array: ");
    for (i = 0; i < newsize; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n\n");

    // free memory
    free(arr2);
    free(arr3);
    printf("Memory freed successfully\n");

    getch();  // Pause screen in Turbo C
    return 0;
}
