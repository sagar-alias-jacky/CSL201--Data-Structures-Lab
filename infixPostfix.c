#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 100

char s[SIZE];
int top = -1;

void push(char elem)
{
    s[++top] = elem;
}

char pop()
{
    return (s[top--]);
}

int pr(char elem)
{
    switch (elem)
    {
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '^':
        return 4;
    }
}

void infixToPostfix(char *infix, char *postfix)
{
    char ch, elem;
    int i = 0, k = 0;

    push('(');

    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')')
        {
            while (s[top] != '(')
                postfix[k++] = pop();
            elem = pop();
        }
        else
        {
            while (pr(s[top]) >= pr(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (s[top] != '(')
        postfix[k++] = pop();

    postfix[k] = '\0';
}

int evalPostfix(char *postfix)
{
    char ch;
    int i = 0, op2, op1;
    while ((ch = postfix[i++]) != '\0')
    {
        if (isdigit(ch))
            push(ch - '0');
        else
        {
            op1 = pop();
            op2 = pop();
            switch (ch)
            {
            case '+':
                push(op2 + op1);
                break;
            case '-':
                push(op2 - op1);
                break;
            case '*':
                push(op2 * op1);
                break;
            case '/':
                push(op2 / op1);
                break;
            case '^':
                push((int)pow(op2, op1));
                break;
            }
        }
    }
    return s[top];
}

void main()
{

    char infix[50], postfix[50];
    int choice;
    while (1)
    {
        printf("\nMENU:");
        printf("\n1.Infix to postfix");
        printf("\n2.Postfix evaluation");
        printf("\n3.Exit\n");
        printf("\nEnter a choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the infix expression: ");
            scanf("%s", &infix);
            infixToPostfix(infix, postfix);
            printf("\nGiven infix expression: %s", infix);
            printf("\nPostfix expression: %s\n", postfix);
            top = -1;
            break;

        case 2:
            printf("\nResult of evaluation of the postfix expression : %d\n", evalPostfix(postfix));
            break;

        case 3:
            exit(0);

        default:
            printf("\nPlease enter a valid choice\n");
            break;
        }
    }
}