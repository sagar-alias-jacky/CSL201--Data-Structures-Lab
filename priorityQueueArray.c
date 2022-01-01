#include <stdio.h>
#include <stdlib.h>

struct element
{
    int data;
    int priority;
};

struct pQueue
{
    int size;
    int front;
    int rear;
    struct element *arr;
};

int isFull(struct pQueue *q)
{
    if ((q->front == 0) && q->rear == (q->size - 1) || (q->rear + 1 == q->front))
        return 1;

    return 0;
}

int isEmpty(struct pQueue *q)
{
    if (q->front == -1)
        return 1;
    return 0;
}

void display(struct pQueue *q)
{
    if (isEmpty(q))
        printf("\nThe priority queue is empty\n");
    else
    {
        printf("\n");
        printf("The present state of the priority queue:\n");

        int i = q->front;

        while (i != q->rear)
        {
            printf("%d-->%d\n", q->arr[i].data, q->arr[i].priority);
            i = (i + 1) % q->size;
        }
        printf("%d-->%d\n", q->arr[i].data, q->arr[i].priority);
    }
}

void enqueue(struct pQueue *q)
{
    struct element temp;

    if (isFull(q))
        printf("\nPriority queue overflow!\n");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear = (q->rear + 1) % q->size;
        printf("\nEnter a value to be inserted into the priority queue: ");
        scanf("%d", &q->arr[q->rear].data);
        printf("\nEnter the priority: ");
        scanf("%d", &q->arr[q->rear].priority);


        for(int i=q->front;i!=q->rear;i=(i+1)%q->size)
        {
            for(int j=q->front;j!=q->rear;j=(j+1)%q->size)
            {
                if(q->arr[j].priority>q->arr[(j+1)%q->size].priority)
                {
                    temp=q->arr[j];
                    q->arr[j]=q->arr[(j+1)%q->size];
                    q->arr[(j+1)%q->size]=temp;
                }
            }
        }    

        display(q);
    }
}

struct element dequeue(struct pQueue *q)
{
    struct element temp;
    temp.data = -1;

    if (isEmpty(q))
        printf("\nPriority queue underflow!\n");
    else
    {
        temp = q->arr[q->front];
        if (q->front == q->rear)
            q->front = q->rear = -1;
        else
            q->front = (q->front + 1) % q->size;
    }
    return temp;
}

void main()
{
    int choice;
    struct element d;

    struct pQueue q;
    printf("Enter the size of the priority queue: ");
    scanf("%d", &q.size);
    q.front = q.rear = -1;
    q.arr = (struct element *)malloc(q.size * sizeof(struct element));

    while (1)
    {
        printf("\nMENU:\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.IsEmpty\n");
        printf("4.IsFull\n");
        printf("5.Display\n");
        printf("6.Exit\n");

        printf("\nEnter a choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue(&q);
            break;

        case 2:
            d = dequeue(&q);
            if (d.data != -1)
            {
                printf("\nThe dequeued element is %d with priority %d\n", d.data, d.priority);
            }
            display(&q);
            break;

        case 3:
            if (isEmpty(&q))
                printf("\nThe priority queue is empty\n");
            else
                printf("\nThe priority queue is not empty\n");
            break;

        case 4:
            if (isFull(&q))
                printf("\nThe priority queue is full\n");
            else
                printf("\nThe priority queue is not full\n");
            break;

        case 5:
            display(&q);
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("\nPlease enter a valid choice\n");
            break;
        }
    }
}