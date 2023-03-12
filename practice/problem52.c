#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
} node;

node *createnode(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("\nmemory not allocated!\n");
        exit(0);
    }
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

int getheight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int balancefactor(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return getheight(root->left) - getheight(root->right);
    }
}

node *rightrotates(node *x)
{
    node *y = x->left;
    node *T2 = y->right;

    y->right = x;
    x->left = T2;

    x->height = 1 + max(getheight(x->left), getheight(x->right));
    y->height = 1 + max(getheight(y->left), getheight(y->right));

    return y;
}

node *leftrotates(node *y)
{
    node *x = y->right;
    node *T2 = x->left;

    x->left = y;
    y->right = T2;

    x->height = 1 + max(getheight(x->left), getheight(x->right));
    y->height = 1 + max(getheight(y->left), getheight(y->right));

    return x;
}

node *insert(node *root, int val)
{
    if (root == NULL)
    {
        root = createnode(val);
    }
    if (root->data < val)
    {
        root->right = insert(root->right, val);
    }
    if (root->data > val)
    {
        root->left = insert(root->left, val);
    }

    root->height = 1 + max(getheight(root->left), getheight(root->right));

    int bf = balancefactor(root);
    if (bf > 1 && val < root->left->data)
    {
        return rightrotates(root);
    }
    if (bf < -1 && val > root->right->data)
    {
        return leftrotates(root);
    }
    if (bf > 1 && val > root->left->data)
    {
        root->left = leftrotates(root->left);
        return rightrotates(root);
    }
    if (bf < -1 && val < root->right->data)
    {
        root->right = rightrotates(root->right);
        return leftrotates(root);
    }
    return root;
}

node *createlist()
{
    int i, n, d;
    node *root = NULL;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the data to be insert in avl tree:");
        scanf("%d", &d);
        root = insert(root, d);
    }
    return root;
}

void preordertraversal(struct node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
}

void postordertraversal(struct node *root)
{
    if (root != NULL)
    {
        postordertraversal(root->left);
        postordertraversal(root->right);
        printf(" %d ", root->data);
    }
}

void inordertraversal(struct node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        printf(" %d ", root->data);
        inordertraversal(root->right);
    }
}

int main()
{
    node *root = createlist();
    printf("\n");
    inordertraversal(root);
    return 0;
}