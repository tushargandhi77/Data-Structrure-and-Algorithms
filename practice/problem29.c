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

int isbst(struct node *root)
{
    struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isbst(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isbst(root->right);
    }
    else
    {
        return 1;
    }
}
struct node *search(struct node *node, int val)
{
    if (node == NULL)
    {
        printf("\nelement not found\n");
        return NULL;
    }
    if (node->data == val)
    {
        printf("\nfound:%d\n", node->data);
        return NULL;
    }
    if (val > node->data)
    {
        return search(node->right, val);
    }
    if (val < node->data)
    {
        return search(node->left, val);
    }
}
struct node *insert(struct node *root, int val)
{
    struct node *prev = NULL, *ptr = NULL;
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
            if (ptr->data > val)
            {
                ptr = ptr->left;
            }
            else if (ptr->data < val)
            {
                ptr = ptr->right;
            }
            else
            {
                printf("enter duplicate value");
            }
        }
        if (prev->data > val)
        {
            prev->left = newnode;
        }
        else
        {
            prev->right = newnode;
        }
    }
    return root;
}
struct node *create_list()
{
    int n, i, d;
    struct node *root = NULL;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter data of node\n");
        scanf("%d", &d);
        root = insert(root, d);
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

int main()
{

    struct node *root = create_list();
    int x, y;
    printf("Enter the element which you want to search in tree:");
    scanf("%d", &x);
    printf("Enter the element to which you delete:");
    scanf("%d", &y);
    printf("\nINordertraversal\n");
    inordertraversal(root);
    printf("\n");
    printf("\npostordertraversal\n");
    postordertraversal(root);
    printf("\n");
    printf("\nPreordertraversal\n");
    preordertraversal(root);

    struct node *n = search(root, x);
    printf("\nAfter deletion\n");
    root = deletenode(root, y);
    printf("INordertraversal\n");
    inordertraversal(root);
    return 0;
}