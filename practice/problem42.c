#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct stack
{
    int size;
    int top;
    char *arr;
};

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

void push(struct stack *ptr, char val)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("stack overflow");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    char val = -1;
    if (ptr->top == -1)
    {
        printf("stack underflow");
    }
    else
    {
        val = ptr->arr[ptr->top];
        ptr->top--;
    }
    return val;
}

char stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int isoperator(char ch)
{
    if (ch == '/' || ch == '*' || ch == '+' || ch == '-')
    {
        return 1;
    }
    return 0;
}

int precedence(char ch)
{
    if (ch == '/' || ch == '*')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
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
    sp->top = -1;
    sp->size = 100;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0, j = 0;
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
            if (precedence(infix[i]) > precedence(stacktop(sp)))
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
    char *exp = "9-2*3/9+2";
    printf("Infix to postfix:%s\n", infixtopostfix(exp));
    return 0;
}