#include <stdio.h>

#define maxNZE 20

void readSM(int[][3]);
void transSM(int[][3], int[][3]);
int addSM(int[][3], int[][3], int[][3]);
void printSM(int[][3]);

void main()
{
    int a[maxNZE][3], b[maxNZE][3], t[maxNZE][3], s[maxNZE][3], choice, sumret;

    while (1)
    {
        printf("MENU:\n\n");
        printf("1.TRANSPOSE A SPARSE MATRIX\n");
        printf("2.ADD TWO SPARSE MATRICES\n");
        printf("3.EXIT\n\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a sparse matrix:\n\n");
            readSM(a);
            printf("\nThe entered sparse matrix is:\n");
            printSM(a);
            transSM(a, t);
            printf("\nThe transpose of the given sparse matrix is:\n");
            printSM(t);
            break;

        case 2:
            printf("Enter the first sparse matrix:\n\n");
            readSM(a);
            printf("\nThe entered sparse matrix is:\n");
            printSM(a);
            printf("Enter the second sparse matrix:\n\n");
            readSM(b);
            printf("\nThe entered second matrix is:\n");
            printSM(b);
            sumret = addSM(a, b, s);
            if (sumret == 1)
            {
                break;
            }
            printf("\nThe sum of the given sparse matrices is:\n");
            printSM(s);
            break;

        case 3:
            exit(0);

        default:
            printf("\nPlease enter a valid choice.\n");
            break;
        }
    }
}

void readSM(int x[maxNZE][3])
{
    int m, n, nnz;
    printf("\nEnter the number of rows: ");
    scanf("%d", &m);
    printf("\nEnter the number of columns: ");
    scanf("%d", &n);
    printf("\nEnter the number of non zero elements: ");
    scanf("%d", &nnz);

    x[0][0] = m;
    x[0][1] = n;
    x[0][2] = nnz;

    for (int i = 1; i <= nnz; i++)
    {
        printf("\nEnter the triplet(row, column, value): \n");
        scanf("%d%d%d", &x[i][0], &x[i][1], &x[i][2]);
    }
}

void transSM(int x[][3], int y[][3])
{
    int i, j, k, n;
    y[0][0] = x[0][1];
    y[0][1] = x[0][0];
    y[0][2] = x[0][2];

    k = 1;
    n = x[0][2];

    for (i = 0; i < x[0][1]; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == x[j][1])
            {
                y[k][0] = i;
                y[k][1] = x[j][0];
                y[k][2] = x[j][2];
                k++;
            }
        }
    }
}

int addSM(int x[][3], int y[][3], int z[][3])
{
    int i, j, k;

    if (x[0][0] != y[0][0] || x[0][1] != y[0][1])
    {
        printf("The matrices must be of equal sizes to be added. Please enter two matrices of equal size.\n");

        return 1;
    }

    z[0][0] = x[0][0];
    z[0][1] = x[0][1];

    i = 1;
    j = 1;
    k = 1;

    while (i <= x[0][2] && j <= y[0][2])
    {
        if (x[i][0] < y[j][0])
        {

            z[k][0] = x[i][0];

            z[k][1] = x[i][1];

            z[k][2] = x[i][2];

            k++;
            i++;
        }

        else if (y[j][0] < x[i][0])
        {

            z[k][0] = y[j][0];

            z[k][1] = y[j][1];

            z[k][2] = y[j][2];

            k++;
            j++;
        }

        else if (x[i][1] < y[j][1])
        {

            z[k][0] = x[i][0];

            z[k][1] = x[i][1];

            z[k][2] = x[i][2];

            k++;
            i++;
        }

        else if (y[j][1] < x[i][1])
        {
            z[k][0] = y[j][0];

            z[k][1] = y[j][1];

            z[k][2] = y[j][2];

            k++;
            j++;
        }

        else
        {
            z[k][0] = x[i][0];

            z[k][1] = x[i][1];

            z[k][2] = x[i][2] + y[j][2];

            k++;
            i++;
            j++;
        }
    }

    while (i <= x[0][2])
    {
        z[k][0] = x[i][0];

        z[k][1] = x[i][1];

        z[k][2] = x[i][2];

        i++;
        k++;
    }

    while (j <= y[0][2])
    {

        z[k][0] = y[j][0];

        z[k][1] = x[j][1];

        z[k][2] = x[j][2];

        j++;
        k++;
    }

    z[0][2] = k-1;
    return 0;
}

void printSM(int x[][3])
{
    int i, n;
    n = x[0][2];

    printf("\nRow\t\tColumn\t\tValue\n");

    for (i = 0; i <= n; i++)
        printf("%d\t\t%d\t\t%d\n\n", x[i][0], x[i][1], x[i][2]);
}