#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// struct node *root = NULL;

struct node *createnode(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

struct node *insert(struct node *root)
{
    struct node *newnode, *ptr, *prev;
    int d;
    printf("\nEnter the data want to insert:\n");
    scanf("%d", &d);
    newnode = createnode(d);
    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        ptr = root;
        while (ptr != NULL)
        {
            prev = ptr;

            if (ptr->data == d)
            {
                printf("\nSimilar input\n");
                return NULL;
            }
            if (ptr->data > d)
            {
                ptr = ptr->left;
            }
            else if (ptr->data < d)
            {
                ptr = ptr->right;
            }
        }
        if (prev->data > d)
        {
            prev->left = newnode;
        }
        else
        {
            prev->right = newnode;
        }
    }
    return root;
}

struct node *createtree()
{
    int n, i;
    struct node *root = NULL;
    printf("\nEnter the number of nodes in tree\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        root = insert(root);
    }
    return root;
}

void inordertraversal(struct node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        printf("%d ", root->data);
        inordertraversal(root->right);
    }
}

int main()
{
    struct node *root = createtree();
    inordertraversal(root);
}