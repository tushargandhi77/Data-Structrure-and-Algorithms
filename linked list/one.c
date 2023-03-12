#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *Next;
};
void transverse(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->Next;
    }
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 32;
    head->Next = second;
    second->data = 44;
    second->Next = third;
    third->data = 22;
    third->Next = NULL;
    transverse(head);
}
