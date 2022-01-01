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

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

void merge(int arr[], int beg, int mid, int end)
{
    int i = beg, j = mid + 1, index = beg, temp[n], k;
    while ((i <= mid) && (j <= end))
    {
        if (arr[i] < arr[j])
        {
            temp[index] = arr[i];
            i++;
        }
        else
        {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }
    if (i > mid)
    {
        while (j <= end)
        {
            temp[index] = arr[j];
            j++;
            index++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[index] = arr[i];
            i++;
            index++;
        }
    }
    for (k = beg; k < index; k++)
        arr[k] = temp[k];
}

void mergeSort(int arr[], int beg, int end)
{
    int mid;
    if (beg < end)
    {
        mid = (beg + end) / 2;
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n\nMENU:\n");
        printf("1.Quick Sort\n");
        printf("2.Merge Sort\n");
        printf("3.Exit\n");

        printf("\nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            input();
            printf("\nSorting the array using quick sort...\n");
            quickSort(arr, 0, n - 1);
            printf("\nThe array sorted in ascending order is:\n\n");
            display();
            break;

        case 2:
            input();
            printf("\nSorting the array using merge sort...\n");
            mergeSort(arr, 0, n - 1);
            printf("\nThe array sorted in ascending order is:\n\n");
            display();
            break;

        case 3:
            exit(0);

        default:
            printf("\nPlease enter a valid choice.\n");
            break;
        }
    }
}