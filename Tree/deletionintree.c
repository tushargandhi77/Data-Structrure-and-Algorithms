#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("memory not allocated:");
        exit(0);
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root)
{
    int data;
    printf("Enter the data want to insert:");
    scanf("%d", &data);
    struct node *ptr, *prev;
    struct node *newnode = createnode(data);
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
            if (ptr->data > data)
            {
                ptr = ptr->left;
            }
            else if (ptr->data < data)
            {
                ptr = ptr->right;
            }
        }
        if (prev->data > data)
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

struct node *createlist()
{
    struct node *root = NULL;
    int i, n;
    printf("Enter the number of node:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        root = insert(root);
    }
    return root;
}

struct node *del_no_child(struct node *root, struct node *parent, struct node *ptr)
{
    if (parent == NULL)
    {
        root = NULL;
    }
    else if (ptr == parent->left)
    {
        parent->left = NULL;
    }
    else
    {
        parent->right = NULL;
    }
    free(ptr);
    return root;
}

struct node *del_one_child(struct node *root, struct node *parent, struct node *ptr)
{
    struct node *child = NULL;
    if (ptr->right != NULL)
    {
        child = ptr->right;
    }
    else
    {
        child = ptr->left;
    }
    if (parent == NULL)
    {
        root = child;
    }
    else if (ptr == parent->left)
    {
        parent->left = child;
    }
    else
    {
        parent->right = child;
    }
    free(ptr);
    return root;
}

struct node *del_two_child(struct node *root, struct node *parent, struct node *ptr)
{
    struct node *successor = NULL;
    struct node *p_successor = ptr;
    successor = ptr->right;

    while (successor->left != NULL)
    {
        p_successor = successor;
        successor = successor->right;
    }
    ptr->data = successor->data;
    if (successor->left != NULL || successor->right != NULL)
    {
        root = del_one_child(root, p_successor, successor);
    }
    else
    {
        root = del_no_child(root, p_successor, successor);
    }
    return root;
}

struct node *delete (struct node *root)
{
    int d;
    printf("Enter the data want to delete:");
    scanf("%d", &d);

    struct node *ptr = NULL, *parent = NULL;

    ptr = root;

    while (ptr != NULL)
    {
        if (ptr->data == d)
        {
            break;
        }
        parent = ptr;
        if (d < ptr->data)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    if (ptr == NULL)
    {
        printf("data not found\n");
    }
    else if (ptr->right != NULL && ptr->left != NULL)
    {
        root = del_two_child(root, parent, ptr);
    }
    else if (ptr->right != NULL || ptr->left != NULL)
    {
        root = del_one_child(root, parent, ptr);
    }
    else
    {
        root = del_no_child(root, parent, ptr);
    }
    return root;
}

void preorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
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
        printf("%d\t", root->data);
    }
}

void inorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d\t", root->data);
        inorder_traversal(root->right);
    }
}

int main()
{
    struct node *root = createlist();

    int x;
    while (1)
    {
        printf("\nEnter 1 for  insert\nEnter 2 for deletetree\nEnter 3 for preordertraversal\nEnter 4 for postordertraversal\nEnter 5 for inordertravresal\nEnter 6 for exit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            root = insert(root);
            printf("\n");
            inorder_traversal(root);
            printf("\n");
            break;
        case 2:
            root = delete (root);
            printf("\n");
            inorder_traversal(root);
            printf("\n");
            break;
            ;
        case 3:
            printf("\nThe preordertraversal:\n");
            preorder_traversal(root);
            printf("\n");
            break;
        case 4:
            printf("\nThe postordertraversal:\n");
            postorder_traversal(root);
            printf("\n");
            break;
        case 5:
            printf("\nThe inordertraversal:\n");
            inorder_traversal(root);
            printf("\n");
            break;
        case 6:
            exit(0);
            break;
            printf("\nEnter valid input\n");
            break;
        }
    }
} 