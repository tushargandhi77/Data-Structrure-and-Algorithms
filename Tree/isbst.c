#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *crete_node(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->left = NULL;
    newnode->data = val;
    newnode->right = NULL;
};

struct node *insertatleft(struct node *root, int val)
{
    root->left = crete_node(val);
    return root->left;
}

struct node *insertatright(struct node *root, int val)
{
    root->right = crete_node(val);
    return root->right;
}

void preordertraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("\t%d", &root->data);
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
        printf("\t%d", root->data);
    }
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

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

int main()
{
    struct node *root = crete_node(5);

    insertatleft(root, 3);
    insertatright(root, 6);

    insertatleft(root->left, 1);
    insertatright(root->left, 4);

    printf("\ninordrtraversal\n");
    inordertraversal(root);

    printf("\nIsbst:%d\n", isBST(root));

    struct node *n = search(root, 11);
    if (n != NULL)
    {
        printf("\nfound: %d\n", n->data);
    }
    else
    {
        printf("\nElement not found\n");
    }
}