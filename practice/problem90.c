#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        root = createnode(data);
    }
    if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    if (root->data < data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

struct node *createtree()
{
    int n, i, d;
    struct node *root = NULL;
    printf("\nEnter the number of nodes in tree\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the data want to insert:\n");
        scanf("%d", &d);
        root = insert(root, d);
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