#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node *createnode(int val)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    new->left = NULL;
    new->right = NULL;
    new->height = 1;
    return new;
}

int getheight(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

int balancefactor(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getheight(root->left) - getheight(root->right);
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

    x->height = 1 + max(getheight(x->right), getheight(x->left));
    y->height = 1 + max(getheight(y->right), getheight(y->left));

    return x;
}

struct node *leftrotates(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getheight(x->right), getheight(x->left));
    y->height = 1 + max(getheight(y->right), getheight(y->left));

    return y;
}

struct node *insert(struct node *root, int val)
{
    if (root == NULL)
    {
        return createnode(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    if (val > root->data)
    {
        root->right = insert(root->right, val);
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

void inordertraversal(struct node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        printf("\t%d", root->data);
        inordertraversal(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    int x, y;
    while (1)
    {
        printf("\nEnter 1 for insert in avl bst\nEnter 2 for inodertraversal in tree\nEnter 3 for exit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("Enter the value to be insert in Avl Bst:");
            scanf("%d", &y);
            root = insert(root, y);
            break;
        case 2:
            printf("The in order traversal\n");
            inordertraversal(root);
            printf("\n");
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("enter valid input");
            break;
        }
    }
}