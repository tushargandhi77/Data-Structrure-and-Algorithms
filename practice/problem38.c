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
        printf("element not found:");
        return NULL;
    }
    if (root->data == val)
    {
        printf("elment found:%d\n", val);
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
    struct node *newnode, *prev = NULL, *ptr = NULL;
    newnode = createnode(val);
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
                printf("dublicate data!");
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
    return root;
}

struct node *createlist()
{
    struct node *root = NULL;
    int i, n, d;
    printf("Enter the number of  node:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the data for tree");
        scanf("%d", &d);
        root = insert(root, d);
    }
    return root;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ", root->data);
    }
}
int main()
{
    struct node *root = createlist();

    int i, x, d;
    while (1)
    {
        printf("Enter 1 for insert\nEnter 2 for inodertraversal\nEnter 3 for exit\nEnter 4 for delete\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("Enter the value to be insert:");
            scanf("%d", &d);
            root = insert(root, d);
            break;
        case 2:
            inorder(root);
            printf("\n");
            break;
        case 3:
            exit(0);
            break;
        case 4:
            printf("Enter the value want to be delete:");
            scanf("%d", &i);
            deletenode(root, i);
            inorder(root);
            printf("\n");
            break;
        default:
            break;
        }
    }
}
