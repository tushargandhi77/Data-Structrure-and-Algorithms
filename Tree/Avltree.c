#include "stdio.h"
#include "stdlib.h"

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int getHeight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct node *createnode(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getbalancefactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
}

struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return createnode(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }

    node->height = 1 + max(getHeight(node->left),getHeight(node->right));

    int bf = getbalancefactor(node);

    if (bf > 1 && key < node->left->key)
    {
        return rightrotate(node);
    }
    if (bf < -1 && key > node->right->key)
    {
        return leftrotate(node);
    }
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
    return node;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}

int main()
{
    struct node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preorder(root);
    printf("\n");
    inorder(root);
    return 0;
}