// The tree all functions

#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insertatleft(struct node *root, int val)
{
    root->left = createnode(val);
    return root->left;
}

struct node *insertatright(struct node *root, int val)
{
    root->right = createnode(val);
    return root->right;
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

struct node *search(struct node *root, int val)
{
    if (root == NULL)
    {
        printf("element not found\n");
        return NULL;
    }
    if (root->data == val)
    {
        printf("element found:%d\n", root->data);
    }
    if (val > root->data)
    {
        return search(root->right, val);
    }
    if (val < root->data)
    {
        return search(root->left, val);
    }
}

void insert(struct node *root, int val)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == val)
        {
            printf("element not to be inserted,found previously\n");
            exit(0);
        }
        else if (val > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    struct node *newnode = createnode(val);
    if (val > prev->data)
    {
        prev->right = newnode;
    }
    else
    {
        prev->left = newnode;
    }
}
struct node *predecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *deletenode(struct node *root, int val)
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
    else if (val > root->data)
    {
        root->right = deletenode(root->right, val);
    }
    else if (val < root->data)
    {
        root->left = deletenode(root->left, val);
    }
    else
    {
        ipre = predecessor(root);
        root->data = ipre->data;
        root->left = deletenode(root->left, ipre->data);
    }
    return root;
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

int main()
{
    struct node *root = createnode(30);

    insertatleft(root, 15);
    insertatright(root, 40);

    insertatleft(root->left, 7);
    insertatright(root->left, 20);

    if (isBst(root))
    {
        printf("\n The tree is bst\n");
    }
    else
    {
        printf("\nThe tree is not bst\n");
    }

    struct node *n = search(root, 100);

    printf("\nThe preorder traversal\n");
    preordertraversal(root);
    printf("\n");
    printf("\nThe inorder traversal\n");
    inordertraversal(root);
    printf("\n");
    printf("\nThe postorder traversal\n");
    postordertraversal(root);
    printf("\n");

    insert(root, 3);
    printf("\nafter insertion inorder traversal\n");
    inordertraversal(root);

    printf("\nafter deletion inorder traversal\n");
    deletenode(root, 30);
    printf("\n");
    inordertraversal(root);
}