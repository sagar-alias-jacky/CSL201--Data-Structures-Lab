#include <stdio.h>

int arr[100], n;

void input()
{
    int i;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    printf("\nEnter the elements in the array: ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void display()
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void bubbleSort()
{
    int i, j, temp;

    printf("\nSorting the array using bubble sort...\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nThe array sorted in ascending order is:\n\n");
    display();
}

void insertionSort()
{
    int i, j, temp;

    printf("\nSorting the array using insertion sort...\n");
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while ((temp < arr[j]) && (j >= 0))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    printf("\nThe array sorted in ascending order is:\n\n");
    display();
}

int smallest(int a[], int k, int n)
{
    int pos = k, small = a[k], i;
    for (i = k + 1; i < n; i++)
    {
        if (a[i] < small)
        {
            small = a[i];
            pos = i;
        }
    }
    return pos;
}

void selectionSort()
{
    int k, pos, temp;

    printf("\nSorting the array using selection sort...\n");
    for (k = 0; k < n; k++)
    {
        pos = smallest(arr, k, n);
        temp = arr[k];
        arr[k] = arr[pos];
        arr[pos] = temp;
    }

    printf("\nThe array sorted in ascending order is:\n\n");
    display();
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n\nMENU:\n");
        printf("1.Bubble Sort\n");
        printf("2.Insertion Sort\n");
        printf("3.Selection Sort\n");
        printf("4.Exit\n");

        printf("\nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            input();
            bubbleSort();
            break;

        case 2:
            input();
            insertionSort();
            break;

        case 3:
            input();
            selectionSort();
            break;

        case 4:
            exit(0);

        default:
            printf("\nPlease enter a valid choice.\n");
            break;
        }
    }
}