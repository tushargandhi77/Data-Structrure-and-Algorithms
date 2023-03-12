#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct stack
{
    int top;
    int size;
    char *arr;
};

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("stack overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    char val;
    if (isEmpty(ptr))
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int isoperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int presidence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

char *infixtopostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    sp->top = -1;
    sp->size = 100;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        if (!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (presidence(infix[i]) > presidence(stacktop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a+b-c-d*e";
    printf("Infixtopostfix = %s\n", infixtopostfix(infix));
}