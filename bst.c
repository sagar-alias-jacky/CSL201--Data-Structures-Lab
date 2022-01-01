#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
} *root = NULL;

void preorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    }
}

void postorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}
void insert(int val)
{
    struct node *newnode, *nodeptr, *parentptr;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    if (root == NULL)
        root = newnode;
    else
    {
        parentptr = NULL;
        nodeptr = root;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr->data)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }
        if (val < parentptr->data)
            parentptr->left = newnode;
        else
            parentptr->right = newnode;
    }
}
struct node *inordersuccessor(struct node *ptr)
{
    while (ptr != NULL && ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}

struct node *delete (struct node *root, int val)
{
    struct node *temp;

    if (val < root->data)
        root->left = delete (root->left, val);
    else if (val > root->data)
        root->right = delete (root->right, val);
    else
    {
        if (root->left != NULL && root->right != NULL)
        {
            temp = inordersuccessor(root->right);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
        else
        {
            temp = root;
            if (root->left == NULL && root->right == NULL)
            {
                free(root);
                return NULL;
            }
            else if (root->left != NULL)
                root = root->left;
            else
                root = root->right;
            free(temp);
        }
    }
    return root;
}

struct node *search(struct node *root, int val)
{
    if (root == NULL || root->data == val)
        return root;
    else if (val > root->data)
        return search(root->right, val);
    else
        return search(root->left, val);
}

void main()
{
    int val, choice;
    printf("Building tree:\n");
    do
    {
        if (root == NULL)
            printf("\nEnter value of root (-1 to exit): ");
        else
            printf("Enter value of node (-1 to exit): ");
        scanf("%d", &val);
        if (val != -1)
            insert(val);
    } while (val != -1);
    
    while(1)
    {
        printf("\nMENU:\n");
        printf("\n1. Insert\t\t2. Delete\t\t3. Search\t\t4.Preorder traversal");
        printf("\n\n5. Inorder traversal\t6. Postorder traversal\t7.Exit\n");
        printf("\nEnter a choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("\nEnter the node to be inserted: ");
            scanf("%d", &val);
            insert(val);
            printf("\nThe node has been inserted successfully!\n");
            break;

        case 2:
            if (root != NULL)
            {
                printf("\nEnter the node to be deleted: ");
                scanf("%d", &val);
                root = delete (root, val);
                printf("\nThe node has been deleted successfully!\n");
            }
            else
                printf("The BST is empty!");
            break;

        case 3:
            printf("\nEnter node to be searched for: ");
            scanf("%d", &val);
            
            if (search(root, val) != NULL)
                printf("Node found!");
            else
                printf("Node not found!");
            break;
        
        case 4:
            if (root != NULL)
            {
                printf("\nPreorder traversal: ");
                preorder(root);
                printf("\n");
            }
            else
                printf("The BST is empty!\n");
            break;

        case 5:
            if (root != NULL)
            {
                printf("\nInorder traversal: ");
                inorder(root);
                printf("\n");
            }
            else
                printf("The BST is empty!\n");
            break;

        case 6:
            if (root != NULL)
            {
                printf("\nPostorder traversal: ");
                postorder(root);
                printf("\n");
            }
            else
                printf("The BST is empty!\n");
            break;

        case 7:
            exit(0);

        default:
            printf("\nPlease enter a valid choice!\n");    
        }
    }
}