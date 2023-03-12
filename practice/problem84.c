#include "stdio.h"
#include "stdlib.h"

struct stack
{
    int top;
    int size;
    char *a;
};

void initstack(struct stack *ptr, int maxsize)
{
    ptr->top = -1;
    ptr->size = maxsize;
    ptr->a = (char *)malloc(sizeof(char));
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
    if (isFull(ptr))
    {
        printf("Stack is full\n");
        return;
    }
    else
    {
        ptr->top++;
        ptr->a[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    char val;
    if (isEmpty(ptr))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        val = ptr->a[ptr->top];
        ptr->top--;
    }
    return val;
}

char stacktop(struct stack *ptr)
{
    return ptr->a[ptr->top];
}

int isoperator(char a)
{
    if (a == '/' || a == '*' || a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int presedence(char a)
{
    if (a == '/' || a == '*')
    {
        return 3;
    }
    else if (a == '+' || a == '-')
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
    initstack(sp, 200);
    char *postfix = (char *)malloc(200 * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (presedence(infix[i]) > presedence(stacktop(sp)))
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
    char sc[] = "2+3/5-6";
    printf("%s", infixtopostfix(sc));
}