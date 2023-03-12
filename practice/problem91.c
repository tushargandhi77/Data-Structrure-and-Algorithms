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
    struct node *ptr, *prev;
    if (root == NULL)
    {
        root = createnode(data);
    }
    else
    {
        ptr = root;
        while (ptr != NULL)
        {
            prev = ptr;
            if (data > ptr->data)
            {
                ptr = ptr->right;
            }
            else if (data < ptr->data)
            {
                ptr = ptr->left;
            }
        }
        if (data > prev->data)
        {
            prev->right = createnode(data);
        }
        else
        {
            prev->left = createnode(data);
        }
    }
    return root;
}

struct node *createlist()
{
    struct node *root = NULL;
    int i, n, data;
    printf("\nEnter the size of tree\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the data want to insert\n");
        scanf("%d", &data);
        root = insert(root, data);
    }
    return root;
}

int findmin(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

struct node *delete (struct node *root, int item)
{
    struct node *del;
    int min;
    if (root == NULL)
    {
        printf("Element not found");
    }
    else if (root->data == item)
    {
        if (root->left == NULL && root->right == NULL)
        {
            del = root;
            root = NULL;
            free(del);
        }
        else if (root->left == NULL)
        {
            del = root;
            root = root->right;
            free(del);
        }
        else if (root->right == NULL)
        {
            del = root;
            root = root->left;
            free(del);
        }
        else
        {
            min = findmin(root->right);
            root->data = min;
            root->right = delete (root->right, min);
        }
    }
    else if (item < root->data)
    {
        root->left = delete (root->left, item);
    }
    else
    {
        root->right = delete (root->right, item);
    }
    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    int x;
    struct node *root = createlist();
    inorder(root);
    printf("\nEnter the data want to delete\n");
    scanf("%d", &x);
    root = delete (root, x);
    inorder(root);
    return 0;
}