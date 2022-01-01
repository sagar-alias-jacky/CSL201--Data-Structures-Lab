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

void linearSearch()
{
    int i, item;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &item);

    for (i = 0; i < n; i++)
    {
        if (arr[i] == item)
        {
            printf("Element found at index at position %d at index %d\n", (i + 1), i);
            return;
        }
    }
    printf("\nElement not found!\n");
}

void binarySearch()
{
    int i, j, item, temp, beg, mid, end;

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

    printf("\nThe array after sorting is:\n\n");
    display();

    printf("\n\nEnter the element to be searched: ");
    scanf("%d", &item);

    beg = 0;
    end = n - 1;

    while (beg <= end)
    {
        mid = (beg + end) / 2;

        if (arr[mid] == item)
        {
            printf("\nElement found at index at position %d at index %d\n", mid + 1, mid);
            return;
        }
        else if (arr[mid] < item)
            beg = mid + 1;
        else
            end = mid - 1;
    }

    printf("\nElement not found!\n");
}

void display()
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void main()
{
    int choice;
    while (1)
    {
        printf("\nMENU:\n");
        printf("1:Linear Search\n");
        printf("2.Binary Search\n");
        printf("3.Exit\n");

        printf("\nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            input();
            linearSearch();
            break;

        case 2:
            input();
            binarySearch();
            break;

        case 3:
            exit(0);

        default:
            printf("\nPlease enter a valid choice.\n");
            break;
        }
    }
}