#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *buildTree()
{
    char ch;
    node *n;
    int x;
    printf("Enter the data to be stored in the node: ");
    scanf("%d", &x);
    getchar();

    n = (node *)malloc(sizeof(node));
    n->data = x;

    printf("\nDoes the node %d have a left child?Y/N?: ", n->data);
    scanf("%c", &ch);
    getchar();

    if (ch == 'y' || ch == 'Y')
    {
        n->left = buildTree();
    }
    else
        n->left = NULL;

    printf("\nDoes the node %d have a right child?Y/N?: ", n->data);
    scanf("%c", &ch);
    getchar();

    if (ch == 'y' || ch == 'Y')
    {
        n->right = buildTree();
    }
    else
        n->right = NULL;

    return n;
}

node *searchnode(node *ptr, int key)
{
    if (ptr == NULL || ptr->data == key)
        return ptr;
    else
    {
        if (searchnode(ptr->left, key) == NULL)
        {
            searchnode(ptr->right, key);
        }
    }
}

void insert(node *root, int key)
{
    char ch;
    int data;
    node *ptr;

    ptr = searchnode(root, key);

    if (ptr == NULL)
    {
        printf("Parent node not found!");
        return;
    }

    if (ptr->left == NULL || ptr->right == NULL)
    {
        printf("Insert as left child or right child?L/R?");
        scanf("%c", &ch);
        // getchar();
        if (ch == 'L' || ch == 'l')
        {
            if (ptr->left == NULL)
            {
                printf("Enter the data of the new node: ");
                scanf("%d", &data);
                node *newnode = (node *)malloc(sizeof(node));
                newnode->data = data;
                newnode->left = newnode->right = NULL;
                ptr->left = newnode;
            }
            else
                printf("The left child is not empty!");
        }
        else
        {
            if (ptr->right == NULL)
            {
                printf("Enter the data of the new node: ");
                scanf("%d", &data);
                node *newnode = (node *)malloc(sizeof(node));
                newnode->data = data;
                newnode->left = newnode->right = NULL;
                ptr->right = newnode;
            }
            else
                printf("The right child is not empty!");
        }
    }
    else
        printf("Both the left and right children are not empty!");

    return;
}

node *searchparent(node *ptr, int data)
{
    if (ptr == NULL)
        return ptr;
    else if (ptr->left != NULL && ptr->right == NULL)
    {
        if (ptr->left->data == data)
            return ptr;
        else
            searchparent(ptr->left, data);
    }
    else if (ptr->left == NULL && ptr->right != NULL)
    {
        if (ptr->right->data == data)
            return ptr;
        else
            searchparent(ptr->right, data);
    }
    else if (ptr->left != NULL && ptr->right != NULL)
    {
        if (ptr->right->data == data || ptr->left->data == data)
            return ptr;
        else
        {
            if (searchparent(ptr->left, data) == NULL)
                searchparent(ptr->right, data);
        }
    }
}

node *delete (node *root, int data)
{
    node *ptr = NULL, *parent = NULL;
    if (root == NULL)
    {
        return root;
    }
    else if (root->data == data && root->left == NULL && root->right == NULL)
    {
        free(root);
        root = NULL;
    }
    else
    {
        ptr = searchnode(root, data);
        if (ptr == NULL)
            printf("Node not found!");
        else
        {
            if (ptr->left == NULL && ptr->right == NULL)
            {
                parent = searchparent(root, data);
                if (parent->left == ptr)
                    parent->left = NULL;
                else
                    parent->right = NULL;
                free(ptr);
            }
            else
                printf("\nThe entered node is not a leaf node!");
        }
    }
    return root;
}

void displayPreorder(node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        displayPreorder(ptr->left);
        displayPreorder(ptr->right);
    }
}

void main()
{
    int choice, data;

    printf("Enter the data for the root node:\n\n");
    node *root;
    root = buildTree();
    printf("\nThe present state of the binary tree is:\n");
    displayPreorder(root);

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
            insert(root, data);
            printf("\nThe present state of the binary tree is:\n");
            displayPreorder(root);
            break;

        case 2:
            printf("\nEnter the node to be deleted: ");
            scanf("%d", &data);
            root = delete (root, data);
            if (root != NULL)
            {
                printf("\nThe present state of the binary tree is:\n");
                displayPreorder(root);
            }
            else
                printf("\nThe binary tree is empty!");
            break;

        case 3:
            printf("\nEnter the node to be searched for: ");
            scanf("%d", &data);
            if (searchnode(root, data) != NULL)
                printf("\nNode found!");
            else
                printf("\nNode not found!");
            break;

        case 4:
            exit(0);

        default:
            printf("\nPlease enter a valid choice.\n");
            break;
        }
    }
}