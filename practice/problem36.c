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

struct node *search(struct node *root, int val)
{
    if (root == NULL)
    {
        printf("Element not found!");
        return NULL;
    }
    if (val == root->data)
    {
        printf("Element found:%d\n", val);
        return NULL;
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

struct node *insert(struct node *root, int val)
{
    struct node *ptr = NULL, *prev = NULL;
    struct node *newnode = createnode(val);
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
            else if (val < ptr->data)
            {
                ptr = ptr->left;
            }
            else
            {
                printf("dublicate element!");
            }
        }
        if (val > prev->data)
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
    else if (root->data > val)
    {
        root->left = deletenode(root->left, val);
    }
    else if (root->data < val)
    {
        root->right = deletenode(root->right, val);
    }
    else
    {
        ipre = predecessor(root);
        root->data = ipre->data;
        root->left = deletenode(root->left, ipre->data);
    }
}
struct node *createlist()
{
    struct node *root = NULL;
    int i, n, d;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the data to tree:");
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
void preordertraversal(struct node *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->data);
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
        printf(" %d ", root->data);
    }
}
void main()
{
    struct node *root = createlist();
    inordertraversal(root);
    printf("\n");
    root = deletenode(root, 10);
    inordertraversal(root);
}