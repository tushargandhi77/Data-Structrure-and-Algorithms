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
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
}

struct node *insertleft(struct node *root, int val)
{
    root->left = create_node(val);
    return root->left;
}

struct node *insertright(struct node *root, int val)
{
    root->right = create_node(val);
    return root->right;
}

void preorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        printf("\t%d", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("\t%d", root->data);
    }
}

void inorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("\t%d", root->data);
        inorder_traversal(root->right);
    }
}

int main()
{
    struct node *root = create_node(1);

    insertleft(root, 2);
    insertright(root, 3);

    insertleft(root->left, 4);
    insertright(root->left, 5);

    printf("The preordertraversal\n");
    preorder_traversal(root);

    printf("\nThe postordertraversal\n");
    postorder_traversal(root);

    printf("\nThe inordertraversal\n");
    inorder_traversal(root);
}