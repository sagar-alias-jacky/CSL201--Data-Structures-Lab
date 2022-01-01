#include <stdio.h>

int stack[50], top = -1, n;

void push();
void pop();
int peek();
int isempty();
int isfull();
void display();

void main()
{
    int choice, e, f;
    printf("Enter the size of the stack(max 50): ");
    scanf("%d", &n);

    while (1)
    {
        printf("\nSTACK OPERATIONS MENU:\n\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.IsEmpty\n");
        printf("5.IsFull\n");
        printf("6.Display\n");
        printf("7.Exit\n\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            printf("\nThe topmost element of the stack is %d\n", peek());
            break;

        case 4:
            e = isempty();

            if (e == 1)
            {
                printf("\nThe stack is empty\n");
            }
            else
            {
                printf("\nThe stack is not empty\n");
            }

            break;

        case 5:
            f = isfull();

            if (f == 1)
            {
                printf("\nThe stack is full\n");
            }
            else
            {
                printf("\nThe stack is not full\n");
            }

            break;

        case 6:
            display();
            break;

        case 7:
            exit(0);
            break;

        default:
            printf("Enter a valid choice.\n");
            break;
        }
    }
}

void push()
{
    int x;

    if (top >= n - 1)
    {
        printf("\nStack Overflow!\n");
    }
    else
    {
        printf("\nEnter a value to be pushed into the stack: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        display();
    }
}

void pop()
{
    if (top < 0)
    {
        printf("\nStack Underflow!\n");
    }
    else
    {
        printf("\nThe popped element is %d\n", stack[top]);
        top--;
        display();
    }
}

int peek()
{
    return stack[top];
}

int isempty()
{
    if (top < 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull()
{
    if (top >= n - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display()
{
    if (top < 0)
    {
        printf("\nStack is empty!\n");
    }
    else
    {
        printf("\nThe present state of the stack is:\n\n");

        printf("%d ----->top\n", stack[top]);

        for (int i = top - 1; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}