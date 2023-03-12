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
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    new->left = NULL;
    new->right = NULL;
    return new;
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

int isBst(struct node *root)
{
    struct node *prev = NULL;
    if (root != NULL)
    {
        if ((!isBst(root->left)))
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
        return NULL;
    }
    if (root->data == val)
    {
        printf("Element found:%d\n", root->data);
    }
    else if (val > root->data)
    {
        return search(root->right, val);
    }
    else if (val < root->data)
    {
        return search(root->left, val);
    }
}

void insertion(struct node *root, int val)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == val)
        {
            printf("insertion not possible already present\n");
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
    struct node *new = create_node(val);
    if (val > prev->data)
    {
        prev->right = new;
    }
    else
    {
        prev->left = new;
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
    if (val > root->data)
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
    struct node *root = create_node(50);

    insertatleft(root, 25);
    insertatright(root, 75);

    insertatleft(root->left, 15);
    insertatright(root->left, 35);

    insertatleft(root->left->right, 30);
    insertatright(root->left->right, 45);

    insertatleft(root->right, 65);
    insertatright(root->right, 85);

    insertatleft(root->right->left, 60);
    insertatright(root->right->left, 70);

    insertatright(root->right->right, 90);

    if (isBst(root))
    {
        printf("\nthe tree is bst\n");
    }
    else
    {
        printf("\nThe tree is not bst");
    }

    struct node *n = search(root, 30);
    if (n == NULL)
    {
        printf("element not found");
    }

    inordertraversal(root);
    // printf("\n");
    // deletenode(root, 45);
    // inordertraversal(root);
}