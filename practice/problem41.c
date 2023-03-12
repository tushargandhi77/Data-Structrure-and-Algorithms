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
    newnode->data = val;
    newnode->height = 1;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
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

int max(int a, int b)
{
    return (a > b) ? a : b;
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
    struct node *newnode, *ptr = NULL, *prev = NULL;
    newnode = createnode(val);
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
            if (val > ptr->data)
            {
                ptr = ptr->right;
            }
            if (val < ptr->data)
            {
                ptr = ptr->left;
            }
            else
            {
                printf("dublicate value!");
            }
        }
        if (prev->data < val)
        {
            prev->right = newnode;
        }
        else
        {
            prev->left = newnode;
        }
    }
    return root;
}

struct node *insertinavl(struct node *root, int val)
{
    if (root == NULL)
    {
        root = createnode(val);
    }
    if (val < root->data)
    {
        root->left = insertinavl(root->left, val);
    }
    if (val > root->data)
    {
        root->right = insertinavl(root->right, val);
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

struct node *createlistforavl()
{
    struct node *root = NULL;
    int i, n, d;
    printf("Enter the number of nodes for avl tree:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the data to insert:");
        scanf("%d", &d);
        root = insertinavl(root, d);
    }
    return root;
}
struct node *createlist()
{
    struct node *root = NULL;
    int i, n, d;
    printf("Enter the number of nodes :");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the data to insert:");
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
        printf(" %d ", root->data);
        inordertraversal(root->right);
    }
}

int main()
{
    struct node *root = createlist();
    inordertraversal(root);
}