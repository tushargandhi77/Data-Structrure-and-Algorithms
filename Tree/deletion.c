#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->left = NULL;
    n->right = NULL;
    n->data = val;
    return n;
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

void preordertraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("\t%d", root->data);
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

int isBst(struct node *root)
{
    struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBst(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBst(root->right);
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
    if (root->data == key)
    {
        return root;
    }
    else if (root->data < key)
    {
        return search(root->right, key);
    }
    else
    {
        return search(root->left, key);
    }
}

struct node *inorderprecedence(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *deletenode(struct node *root, int value)
{
    struct node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (value < root->data)
    {
        root->left = deletenode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deletenode(root->right, value);
    }
    else
    {
        ipre = inorderprecedence(root);
        root->data = ipre->data;
        root->left = deletenode(root->left, ipre->data);
    }
    return root;
}

int main(){
    struct node *root =  create_node(5);

    insertatleft(root,3);
    insertatright(root,6);
    
    insertatleft(root->left,1);
    insertatright(root->left,4);

    inordertraversal(root);
    printf("\n");
    deletenode(root,3);
    inordertraversal(root);
}