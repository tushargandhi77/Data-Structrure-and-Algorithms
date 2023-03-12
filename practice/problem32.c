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
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("elemnt not found");
        return NULL;
    }
    if (root->data == key)
    {
        printf("element found:%d\n", root->data);
        return NULL;
    }
    if (key > root->data)
    {
        return search(root->right, key);
    }
    if (key < root->data)
    {
        return search(root->left, key);
    }
}

struct node *insert(struct node *root, int val)
{
    struct node *prev = NULL, *ptr = NULL;
    struct node *newnode = create_node(val);
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
                printf("duplicate elment!");
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

struct node *createlist()
{
    struct node *root = NULL;
    int i, n, d;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the data to insert in tree:");
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
        printf("not found\n");
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
    if (val < root->data)
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

void main()
{
    struct node *root = createlist();
    inordertraversal(root);
    deletenode(root, 10);
    printf("\n");
    inordertraversal(root);
}