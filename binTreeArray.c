#include <stdio.h>
#include <math.h>

int a[100] = {[0 ... 99] = -1};
int size, h, loc = 0;

void display()
{
    if (a[1] == -1)
    {
        printf("The binary tree is empty!");
    }
    int i;
    for (i = 1; i <= size; i++)
    {
        if (a[i] != -1)
            printf("%d ", a[i]);
        else
            printf("- ");
    }
}

void buildtree(int i, int item)
{
    int left, right;
    char ch;

    a[i] = item;
    printf("Does %d have left child?Y/N?: ", a[i]);
    scanf("%c", &ch);
    getchar();
    if (ch == 'y' || ch == 'Y')
    {
        printf("Enter the data of the left child: ");
        scanf("%d", &left);
        getchar();
        buildtree(2 * i, left);
    }
    else
        ;

    printf("Does %d have a right child?Y/N: ", a[i]);
    scanf("%c", &ch);
    getchar();
    if (ch == 'y' || ch == 'Y')
    {
        printf("Enter the data of the right child: ");
        scanf("%d", &right);
        getchar();
        buildtree(2 * i + 1, right);
    }
    else
        ;
}

int search(int i, int key)
{
    if (a[i] == -1 || a[i] == key)
    {
        if (a[i] == key)
            loc = i;
        return i;
    }
    else
    {
        if (a[search(2 * i, key)] == -1)
            search(2 * i + 1, key);
    }
}

void insert(int key)
{
    int item;
    char ch;
    search(1, key);
    if (a[loc] != key)
    {
        printf("Parent node not found!");
        return;
    }
    if (a[2 * loc] == -1 || a[2 * loc + 1] == -1)
    {
        printf("Insert as left child or right child?L/R?: ");
        scanf("%c", &ch);
        getchar();
        if (ch == 'l' || ch == 'L')
        {
            if (a[2 * loc] == -1)
            {
                printf("Enter the data to inserted: ");
                scanf("%d", &item);
                getchar();
                if (2 * loc > size)
                {
                    h++;
                    size = pow(2, h + 1) - 1;
                }
                a[2 * loc] = item;
            }
            else
                printf("The left child is not empty!");
        }
        else
        {
            if (a[2 * loc + 1] == -1)
            {
                printf("Enter the data to be inserted: ");
                scanf("%d", &item);
                getchar();
                if (2 * loc + 1 > size)
                {
                    h++;
                    size = pow(2, h + 1) - 1;
                }
                a[2 * loc + 1] = item;
            }
            else
                printf("The right child is not empty!");
        }
    }
    else
        printf("Both the left and the right children are not empty!");
}

void delete (int key)
{
    int k, flag = 0;
    search(1, key);
    if (a[loc] == key)
    {
        if (a[2 * loc] == -1 && a[2 * loc + 1] == -1)
        {
            a[loc] = -1;
            for (k = pow(2, h); k <= size; k++)
            {
                if (a[k] != -1)
                    flag = 1;
            }
            if (flag == 0)
            {
                h--;
                size = pow(2, h + 1) - 1;
            }
        }
        else
            printf("%d is not a leaf node!", key);
    }
    else
        printf("Node does not exist!");
}

void main()
{
    int i, choice, data;

    printf("Enter height of the tree: ");
    scanf("%d", &h);
    size = pow(2, h + 1) - 1;

    printf("Enter the data to be stored in the root node: ");
    scanf("%d", &data);
    getchar();
    buildtree(1, data);
    printf("\nThe present state of the binary tree is:\n");
    display();

    while (1)
    {
        printf("\n\nMENU:\n");
        printf("1.Insert a new node\n");
        printf("2.Delete a specified node\n");
        printf("3.Search a specified node\n");
        printf("4.Exit\n");

        printf("\nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the data of the parent node, as a child of which the new node is to be created: ");
            scanf("%d", &data);
            getchar();
            insert(data);
            printf("\nThe present state of the binary tree is:\n");
            display();
            break;

        case 2:
            if (h >= 0)
            {
                printf("\nEnter the node to be deleted: ");
                scanf("%d", &data);
                getchar();
                delete (data);
                if (h >= 0)
                {
                    printf("\nThe present state of the binary tree is:\n");
                    display();
                }
                else
                    printf("The binary tree is empty!");
            }
            else
                printf("The binary tree is empty!");
            break;

        case 3:
            printf("\nEnter the node to be searched for: ");
            scanf("%d", &data);
            search(1, data);
            if (a[loc] == data)
                printf("\nNode found!");
            else
                printf("\nNode not found!");

            printf("\nThe present state of the binary tree is:\n");
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("\nPlease enter a valid choice.\n");
            break;
        }
    }
}