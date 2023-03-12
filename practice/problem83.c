#include "stdio.h"
#include "stdlib.h"

struct stack
{
    int top;
    int size;
    char *a;
};

void initstack(struct stack *p)
{
    p->top = -1;
    p->size = 100;
    p->a = (char *)malloc(p->size * sizeof(char));
}

int isEmpty(struct stack *p)
{
    if (p->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *p)
{
    if (p->top == p->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *p, char ch)
{
    if (isFull(p))
    {
        printf("Stack is full\n");
    }
    else
    {
        p->top++;
        p->a[p->top] = ch;
    }
}

char pop(struct stack *p)
{
    char ch;
    ch = p->a[p->top];
    p->top--;
    return ch;
}

int match(char a, char b)
{
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    return 0;
}

int parenthesismatch(char *exp)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    initstack(sp);
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ']' || exp[i] == '}' || exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            if (!match(pop(sp), exp[i]))
            {
                return 0;
            }
        }
        i++;
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *ep = "{((32+345))}";
    if (parenthesismatch(ep))
    {
        printf("Matching succesull\n");
    }
    else
    {
        printf("Matching unsuccesull!!\n");
    }
    return 0;
}