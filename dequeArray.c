#include <stdio.h>
#include <stdlib.h>

struct deque
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct deque *q)
{
    if ((q->front == q->rear + 1) || ((q->front == 0) && (q->rear == q->size - 1)))
        return 1;
    return 0;
}

int isEmpty(struct deque *q)
{
    if (q->front == -1)
        return 1;
    return 0;
}

void display(struct deque *q)
{
    if (isEmpty(q))
        printf("\nThe deque is empty\n");
    else
    {
        printf("\n");
        printf("The present state of the deque:\n");

        int i = q->front;

        while (i != q->rear)
        {
            printf("%d\t", q->arr[i]);
            i = (i + 1) % q->size;
        }
        printf("%d", q->arr[i]);
        printf("\n");
    }
}

void insertFront(struct deque *q)
{
    int val;

    if (isFull(q))
        printf("\nDeque overflow!\n");
    else
    {
        printf("\nEnter a value to be inserted into the deque: ");
        scanf("%d", &val);

        if (q->front == -1)
            q->front = q->rear = 0;
        else if (q->front == 0)
            q->front = q->size - 1;
        else
            q->front--;

        q->arr[q->front] = val;

        display(q);
    }
}

void deleteFront(struct deque *q)
{
    if (isEmpty(q))
        printf("\nDeque underflow\n");
    else
    {
        printf("\nThe dequeued element is %d\n", q->arr[q->front]);

        if (q->front == q->rear)
            q->front = q->rear = -1;
        else
            q->front = (q->front + 1) % q->size;

        display(q);
    }
}

void insertRear(struct deque *q)
{
    int val;

    if (isFull(q))
        printf("\nDeque overflow!\n");
    else
    {
        printf("\nEnter a value to be inserted into the deque: ");
        scanf("%d", &val);

        if (q->front == -1)
            q->front = 0;

        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;

        display(q);
    }
}

void deleteRear(struct deque *q)
{
    if (isEmpty(q))
        printf("\nDeque underflow!\n");
    else
    {
        printf("\nThe dequeued element is %d\n", q->arr[q->rear]);

        if (q->front == q->rear)
            q->front = q->rear = -1;
        else if (q->rear == 0)
            q->rear = q->size - 1;
        else
            q->rear--;

        display(q);
    }
}

void main()
{
    int choice;

    struct deque q;
    printf("Enter the size of the deque: ");
    scanf("%d", &q.size);
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    while (1)
    {
        printf("\nMENU:\n");
        printf("1.Insert from front\n");
        printf("2.Insert from rear\n");
        printf("3.Delete from front\n");
        printf("4.Delete from rear\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("\nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertFront(&q);
            break;

        case 2:
            insertRear(&q);
            break;

        case 3:
            deleteFront(&q);
            break;

        case 4:
            deleteRear(&q);
            break;

        case 5:
            display(&q);
            break;

        case 6:
            exit(0);

        default:
            printf("\nPlease enter a valid choice\n");
            break;
        }
    }
}