#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node *createNode(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
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

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int balancefactor(struct node *root)
{
    if (root != NULL)
    {
        return 0;
    }
    else
    {
        return getheight(root->left) - getheight(root->right);
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
        root = createNode(val);
    }
    if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    if (val < root->data)
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

struct node *create_list()
{
    struct node *root = NULL;
    int i, n, d;
    printf("Enter the number of nodes of AVL:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the value for AVL trees:");
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
        printf("\t%d", root->data);
        inordertraversal(root->right);
    }
}
void preordertraversal(struct node *root)
{
    if (root != NULL)
    {
        preordertraversal(root->left);
        preordertraversal(root->right);
        printf("\t%d", root->data);
    }
}
void postordertraversal(struct node *root)
{
    if (root != NULL)
    {
        postordertraversal(root->left);
        postordertraversal(root->right);
        printf("\t%d", root->data);
    }
}

int main()
{
    struct node *root = create_list();

    inordertraversal(root);
    printf("\n");
    preordertraversal(root);
    printf("\n");
    postordertraversal(root);
    
}