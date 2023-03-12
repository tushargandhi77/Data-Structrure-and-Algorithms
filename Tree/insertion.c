#include "stdio.h"
#include "stdlib.h"

struct node
{
    struct node *left;
    struct node *right;
    int data;
};

struct node *create_node(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insertatleft(struct node *root, int val)
{
    root->left = create_node(val);
    return root->left;
}

struct node *insertatright(struct node *root, int val)
{
    root->right = create_node(val);
    return root->right;
}

void pretraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("\t%d", root->data);
        pretraversal(root->left);
        pretraversal(root->right);
    }
}

void posttraversal(struct node *root)
{
    if (root != NULL)
    {
        posttraversal(root->left);
        posttraversal(root->right);
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

void insertelement(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf("Element is already present in the tree not to be inserted\n");
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    struct node *n = create_node(key);
    if (prev->data > key)
    {
        prev->left = n;
    }
    else if (prev->data < key)
    {
        prev->right = n;
    }
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        printf("Element:%d\n", root->data);
    }
    else if (root->data > key)
    {
        search(root->left, key);
    }
    else if (root->data < key)
    {
        search(root->right, key);
    }
}

int main()
{
    struct node *root = create_node(5);

    insertatleft(root, 3);
    insertatright(root, 6);

    insertatleft(root->left, 1);
    insertatright(root->left, 4);

    insertelement(root, 16);
    printf("%d", root->right->right->data);

}