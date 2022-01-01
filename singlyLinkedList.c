#include <stdio.h>
#include <stdlib.h>

struct element
{
    int data;
    struct element *next;
} * start;

void insertFront()
{
    if (start == NULL)
    {
        struct element *newnode = (struct element *)malloc(sizeof(struct element));
        printf("\nEnter the data to be stored in the new node: ");
        scanf("%d", &newnode->data);
        start = newnode;
        newnode->next = NULL;
        display();
    }
    else
    {
        struct element *newnode = (struct element *)malloc(sizeof(struct element));
        printf("\nEnter the data to be stored in the new node: ");
        scanf("%d", &newnode->data);
        newnode->next = start;
        start = newnode;
        display();
    }
}

void insertEnd()
{
    if (start == NULL)
    {
        struct element *newnode = (struct element *)malloc(sizeof(struct element));
        printf("\nEnter the data to be stored in the new node: ");
        scanf("%d", &newnode->data);
        start = newnode;
        newnode->next = NULL;
        display();
    }
    else
    {
        struct element *ptr;
        struct element *newnode = (struct element *)malloc(sizeof(struct element));
        printf("\nEnter the data to be stored in the new node: ");
        scanf("%d", &newnode->data);
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
        newnode->next = NULL;
        display();
    }
}

void insertAfter()
{
    int val, found = 0;
    struct element *ptr;
    struct element *newnode = (struct element *)malloc(sizeof(struct element));
    printf("\nEnter the value after which the node is to be inserted: ");
    scanf("%d", &val);
    for (ptr = start; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->data == val)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        printf("\nEnter the data to be stored in the new node: ");
        scanf("%d", &newnode->data);
        newnode->next = ptr->next;
        ptr->next = newnode;
        display();
    }
    else
    {
        printf("\nThere is no such element in the linked list\n");
        printf("Please enter an element which is present in the linked list\n");
        display();
    }
}

void deleteFront()
{
    if (start == NULL)
        printf("\nLinked list underflow!\n");
    else
    {
        struct element *ptr;
        ptr = start;
        start = start->next;
        free(ptr);
        display();
    }
}

void deleteEnd()
{
    if (start == NULL)
        printf("\nLinked list underflow!\n");
    else
    {
        struct element *ptr;
        struct element *preptr = (struct element *)malloc(sizeof(struct element));
        ptr = start;
        preptr = start;
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        if (ptr == start)
        {
            start = NULL;
            free(ptr);
        }
        else
        {
            preptr->next = NULL;
            free(ptr);
        }
        display();
    }
}

void deleteSpec()
{
    if (start == NULL)
        printf("\nLinked list underflow!\n");
    else
    {
        int val, found = 0;
        struct element *ptr;
        struct element *preptr;
        ptr = start;
        preptr = start;
        printf("\nEnter the value which is to be deleted: ");
        scanf("%d", &val);
        for (; ptr != NULL;)
        {
            if (ptr->data == val)
            {
                found = 1;
                break;
            }
            preptr = ptr;
            ptr = ptr->next;
        }
        if (found == 1)
        {
            if (ptr == start)
            {
                if (start->next == NULL)
                {
                    start = NULL;
                    free(ptr);
                }
                else
                {
                    start = ptr->next;
                    free(ptr);
                }
            }
            else
            {
                preptr->next = ptr->next;
                free(ptr);
            }
            display();
        }
        else
        {
            printf("\nThere is no such element in the linked list\n");
            printf("Please enter an element which is present in the linked list\n");
            display();
        }
    }
}

void display()
{
    struct element *ptr;
    ptr = start;
    if (start == NULL)
        printf("\nThe linked list is empty!\n");
    else
    {
        printf("\nThe present state of the linked list is:\n");
        while (ptr != NULL)
        {
            printf("%d --> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

void main()
{
    int choice;
    start = NULL;

    while (1)
    {
        printf("\nMENU:\n1.Insert at the beginning\n2.Insert at the end\n3.Insert after a specified node\n4.Delete from the beginning\n5.Delete from the end\n6.Delete a specified node\n7.Display\n8.Exit\n");

        printf("\nEnter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertFront();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            insertAfter();
            break;
        case 4:
            deleteFront();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            deleteSpec();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("\nEnter a valid choice\n");
            break;
        }
    }
}