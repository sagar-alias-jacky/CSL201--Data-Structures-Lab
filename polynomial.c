#include <stdio.h>

struct polynomial
{
    int coeff;
    int expo;
} a[10], b[10], c[20], d[100], temp;

int ReadPoly(struct polynomial[]);
int AddPoly(struct polynomial[], struct polynomial[], struct polynomial[], int, int);
int MultiPoly(struct polynomial[], struct polynomial[], struct polynomial[], int, int);
void DisplayPoly(struct polynomial[], int);

void main()
{
    int aterms, bterms, cterms, dterms, choice;

    while (1)
    {
        printf("MENU:\n\n");
        printf("1.ADD TWO POLYNOMIALS\n");
        printf("2.MULTIPLY TWO POLYNOMIALS\n");
        printf("3.EXIT\n\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the first polynomial:\n");
            aterms = ReadPoly(a);
            printf("The first polynomial is: ");
            DisplayPoly(a, aterms);
            printf("Enter the second polynomial:\n");
            bterms = ReadPoly(b);
            printf("The second polynomial is: ");
            DisplayPoly(b, bterms);

            cterms = AddPoly(a, b, c, aterms, bterms);
            printf("The sum of the given polynomials is: ");
            DisplayPoly(c, cterms);
            break;

        case 2:
            printf("Enter the first polynomial:\n");
            aterms = ReadPoly(a);
            printf("The first polynomial is: ");
            DisplayPoly(a, aterms);
            printf("Enter the second polynomial:\n");
            bterms = ReadPoly(b);
            printf("The second polynomial is: ");
            DisplayPoly(b, bterms);

            dterms = MultiPoly(a, b, d, aterms, bterms);
            printf("The product of the given polynomials is: ");
            DisplayPoly(d, dterms);
            break;

        case 3:
            exit(0);

        default:
            printf("Please enter a valid choice.\n");
            break;
        }
    }
}

int ReadPoly(struct polynomial x[])
{
    int n, i;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    printf("Enter the coefficient and exponent of each term in decreasing order of exponents:\n");

    for (i = 0; i < n; i++)
    {
        printf("Enter the coefficient of term %d: ", i + 1);
        scanf("%d", &x[i].coeff);
        printf("Enter the exponent of term %d: ", i + 1);
        scanf("%d", &x[i].expo);
    }

    return n;
}

int AddPoly(struct polynomial x[], struct polynomial y[], struct polynomial z[], int n1, int n2)
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (x[i].expo == y[j].expo)
        {
            z[k].coeff = x[i].coeff + y[j].coeff;
            z[k].expo = x[i].expo;

            i++;
            j++;
            k++;
        }

        else if (x[i].expo > y[j].expo)
        {
            z[k].coeff = x[i].coeff;
            z[k].expo = x[i].expo;

            i++;
            k++;
        }

        else
        {
            z[k].coeff = y[j].coeff;
            z[k].expo = y[j].expo;

            j++;
            k++;
        }
    }

    while (i < n1)
    {
        z[k].coeff = x[i].coeff;
        z[k].expo = x[i].expo;

        i++;
        k++;
    }

    while (j < n2)
    {
        z[k].coeff = y[j].coeff;
        z[k].expo = y[j].expo;

        j++;
        k++;
    }

    return k;
}

int MultiPoly(struct polynomial x[], struct polynomial y[], struct polynomial z[], int n1, int n2)
{
    int i, j, k = 0, t;

    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            d[k].expo = a[i].expo + b[j].expo;
            d[k].coeff = a[i].coeff * b[j].coeff;

            for (t = k; t > 0; t--)
            {
                if (d[t].expo > d[t - 1].expo)
                {
                    temp = d[t - 1];
                    d[t - 1] = d[t];
                    d[t] = temp;
                }
            }

            k++;
        }
    }

    for (i = 0; i < k - 1; i++)
    {
        for (j = i + 1; j < k;)
        {
            if (d[i].expo == d[j].expo)
            {
                d[i].coeff = d[i].coeff + d[j].coeff;
                for (t = j; t < k; t++)
                {
                    d[t] = d[t + 1];
                }
                k--;
            }
            else
            {
                j++;
            }
        }
    }

    return k;
}

void DisplayPoly(struct polynomial x[], int n)
{
    int i;

    for (i = 0; i < n - 1; i++)
    {
        printf("%dx^%d + ", x[i].coeff, x[i].expo);
    }
    printf("%dx^%d\n\n", x[i].coeff, x[i].expo);
}