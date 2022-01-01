#include <stdio.h>
#include <stdlib.h>
struct linearQueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

struct circularQueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int linearIsFull(struct linearQueue *q)
{
    if (q->rear == q->size - 1)
        return 1;
    return 0;
}

int circularIsFull(struct circularQueue *q)
{
    if ((q->front == 0) && q->rear == (q->size - 1) || (q->rear + 1 == q->front))
        return 1;

    return 0;
}

int linearIsEmpty(struct linearQueue *q)
{
    if (q->front == -1)
        return 1;

    return 0;
}

int circularIsEmpty(struct circularQueue *q)
{
    if (q->front == -1)
        return 1;

    return 0;
}

void Display(struct linearQueue *q)
{
    if (linearIsEmpty(q))
        printf("\nThe linear queue is empty\n");
    else
    {
        printf("\n");
        printf("The present state of the linear queue:\n");

        for (int i = (q->front); i <= q->rear; i++)
            printf("%d\t", q->arr[i]);

        printf("\n");
    }
}

void cDisplay(struct circularQueue *q)
{
    if (circularIsEmpty(q))
        printf("\nThe circular queue is empty\n");
    else
    {
        printf("\n");
        printf("The present state of the circular queue:\n");

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

void linearEnqueue(struct linearQueue *q)
{
    int val;

    if (linearIsFull(q))
        printf("\nLinear queue overflow!\n");
    else
    {
        printf("\nEnter a value to be inserted into the linear queue: ");
        scanf("%d", &val);
        q->rear++;
        q->arr[q->rear] = val;
        if (q->front == -1)
            q->front = 0;
        Display(q);
    }
}

void circularEnqueue(struct circularQueue *q)
{
    int val;

    if (circularIsFull(q))
        printf("\nCircular queue overflow!\n");
    else
    {
        printf("\nEnter a value to be inserted into the circular queue: ");
        scanf("%d", &val);
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
        if (q->front == -1)
            q->front = 0;
        cDisplay(q);
    }
}

int linearDequeue(struct linearQueue *q)
{
    int d = -1;
    if (linearIsEmpty(q))
        printf("\nLinear queue underflow!\n");
    else
    {
        d = q->arr[q->front];
        if (q->front == q->rear)
            q->front = q->rear = -1;
        else
            q->front++;
    }
    return d;
}

int circularDequeue(struct circularQueue *q)
{
    int d = -1;
    if (circularIsEmpty(q))
        printf("\nCircular queue underflow!\n");
    else
    {
        d = q->arr[q->front];
        if (q->front == q->rear)
            q->front = q->rear = -1;
        else
            q->front = (q->front + 1) % q->size;
    }
    return d;
}

void main()
{
    int choice, lChoice, cChoice, dl, dc;

    struct linearQueue q;
    printf("Enter the size of the linear queue: ");
    scanf("%d", &q.size);
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    struct circularQueue cq;
    printf("Enter the size of the circular queue: ");
    scanf("%d", &cq.size);
    cq.front = cq.rear = -1;
    cq.arr = (int *)malloc(cq.size * sizeof(int));

    while (1)
    {
        printf("\nMENU:\n");
        printf("1.Linear Queue\n");
        printf("2.Circular Queue\n");
        printf("3.Exit\n");
        printf("\nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            while (1)
            {
                printf("\nLINEAR QUEUE MENU:\n");
                printf("1.Enqueue\n");
                printf("2.Dequeue\n");
                printf("3.IsEmpty\n");
                printf("4.IsFull\n");
                printf("5.Display linear queue\n");
                printf("6.Return to main menu\n");
                printf("\nEnter a choice: ");
                scanf("%d", &lChoice);

                switch (lChoice)
                {
                case 1:
                    linearEnqueue(&q);
                    break;

                case 2:
                    dl = linearDequeue(&q);
                    if (dl != -1)
                    {
                        printf("\nThe dequeued element is %d\n", dl);
                    }
                    else
                    printf("\nError dequeuing\n");

                    Display(&q);
                    break;

                case 3:
                    if (linearIsEmpty(&q))
                        printf("\nThe linear queue is empty\n");
                    else
                        printf("\nThe linear queue is not empty\n");
                    break;

                case 4:
                    if (linearIsFull(&q))
                        printf("\nThe linear queue is full\n");
                    else
                        printf("\nThe linear queue is not full\n");
                    break;

                case 5:
                    Display(&q);
                    break;

                default:
                    if (lChoice != 6)
                    {
                        printf("\nPlease enter a valid choice\n");
                        break;
                    }
                }
                if (lChoice == 6)
                    break;
            }
            break;

        case 2:
            while (1)
            {
                printf("\nCIRCULAR QUEUE MENU:\n");
                printf("1.Enqueue\n");
                printf("2.Dequeue\n");
                printf("3.IsEmpty\n");
                printf("4.IsFull\n");
                printf("5.Display circular queue\n");
                printf("6.Return to main menu\n");
                printf("\nEnter a choice: ");
                scanf("%d", &cChoice);

                switch (cChoice)
                {
                case 1:
                    circularEnqueue(&cq);
                    break;

                case 2:
                    dc = circularDequeue(&cq);
                    if (dc != -1)
                    {
                        printf("\nThe dequeued element is %d\n", dc);
                    }
                    else
                        printf("\nError Dequeuing\n");

                    cDisplay(&cq);
                    break;

                case 3:
                    if (circularIsEmpty(&cq))
                        printf("\nThe circular queue is empty\n");
                    else
                        printf("\nThe circular queue is not empty\n");
                    break;

                case 4:
                    if (circularIsFull(&cq))
                        printf("\nThe circular queue is full\n");
                    else
                        printf("\nThe circular queue is not full\n");
                    break;

                case 5:
                    cDisplay(&cq);
                    break;

                default:
                    if (cChoice != 6)
                    {
                        printf("\nPlease enter a valid choice\n");
                        break;
                    }
                }
                if (cChoice == 6)
                    break;
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Please enter a valid choice.");
            break;
        }
    }
}