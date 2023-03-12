#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
};

struct node *createnode(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("memory not allocated!");
        exit(0);
    }
    newnode->data = val;
    newnode->height = 1;
    newnode->left = NULL;
    newnode->right = NULL;
}

int getheight(struct node *root)
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

int balancefactor(struct node *root)
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

struct node *search(struct node *root)
{
    int d;
    printf("Enter the value want to search:");
    scanf("%d", &d);
    if (root == NULL)
    {
        printf("Element not found!");
    }
    else if (root->data == d)
    {
        printf("elemet found :%d\n", d);
    }
    else if (d > root->data)
    {
        return search(root->right);
    }
    else if (d < root->data)
    {
        return search(root->left);
    }
}

struct node *rightrotates(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = 1 + max(getheight(x->left), getheight(x->right));
    y->height = 1 + max(getheight(y->left), getheight(y->right));

    return x;
}

struct node *leftrotates(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getheight(x->left), getheight(x->right));
    y->height = 1 + max(getheight(y->left), getheight(y->right));

    return y;
}

struct node *insert(struct node *root, int val)
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
    if (bf > 1 && val > root->right->data)
    {
        root->right = rightrotates(root->right);
        return leftrotates(root);
    }
    if (bf < -1 && val < root->left->data)
    {
        root->left = leftrotates(root->left);
        return rightrotates(root);
    }

    return root;
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
struct node *createlist()
{
    struct node *root = NULL;
    int i, n, d;
    printf("Enter the number of node:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the data at node %d:", i + 1);
        scanf("%d", &d);
        root = insert(root, d);
    }
    return root;
}

int main()
{
    struct node *root = createlist();
    inordertraversal(root);
}