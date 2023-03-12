#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct stack
{
    int top;
    int size;
    char *arr;
};

int isfull(struct stack *ptr)
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

int isempty(struct stack *ptr)
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
    if (isfull(ptr))
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
    if (isempty(ptr))
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
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
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

int isoperator(char ch)
{
    if (ch == '+' || ch == '*' || ch == '/' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char *infixtopostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));

    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(struct stack));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(struct stack));

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
    while (!isempty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a-b+c*d";
    printf("The postfix expression:%s\n", infixtopostfix(infix));
    return 0;
}