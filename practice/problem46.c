#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} suhani;

suhani *createnode(int data)
{
    suhani *newnode = (suhani *)malloc(sizeof(suhani));
    newnode->data = data;
    newnode->right = NULL;
    newnode->left = NULL;
    return newnode;
}

suhani *insert(suhani *root)
{
    int d;
    printf("Enter the data to be insert:");
    scanf("%d", &d);
    suhani *newnode, *parent, *ptr;
    newnode = createnode(d);
    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        ptr = root;
        while (ptr != NULL)
        {
            parent = ptr;
            if (ptr->data < d)
            {
                ptr = ptr->right;
            }
            else if (ptr->data > d)
            {
                ptr = ptr->left;
            }
            else
            {
                printf("duplicate value!!");
            }
        }
        if (parent->data < d)
        {
            parent->right = newnode;
        }
        else
        {
            parent->left = newnode;
        }
    }
    return root;
}

suhani *createlist()
{
    suhani *root = NULL;
    int i, n;
    printf("Enter number of node:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        root = insert(root);
    }
    return root;
}

suhani *del_no_node(suhani *root, suhani *parent, suhani *ptr)
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

suhani *del_one_node(suhani *root, suhani *parent, suhani *ptr)
{
    suhani *child = NULL;
    if (ptr->left != NULL)
    {
        child = ptr->left;
    }
    else
    {
        child = ptr->right;
    }
    if (parent == NULL)
    {
        root = child;
    }
    else if (parent->left == ptr)
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

suhani *del_two_node(suhani *root, suhani *parent, suhani *ptr)
{
    suhani *successor = NULL;
    suhani *p_successor = ptr;

    successor = ptr->right;
    while (successor->left != NULL)
    {
        p_successor = successor;
        successor = successor->left;
    }
    ptr->data = successor->data;
    if (successor->left != NULL || successor->right != NULL)
    {
        root = del_one_node(root, p_successor, successor);
    }
    else
    {
        root = del_no_node(root, p_successor, successor);
    }
    return root;
}

suhani *delete (suhani *root)
{
    int d;
    printf("Enter the data to be delete:");
    scanf("%d", &d);
    suhani *parent = NULL, *ptr = NULL;

    ptr = root;
    while (ptr != NULL)
    {
        if (ptr->data == d)
        {
            break;
        }
        parent = ptr;
        if (ptr->data > d)
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
        printf("Element not found!!");
    }
    else if (ptr->left != NULL && ptr->right != NULL)
    {
        root = del_two_node(root, parent, ptr);
    }
    else if (ptr->left != NULL || ptr->right != NULL)
    {
        root = del_one_node(root, parent, ptr);
    }
    else
    {
        root = del_no_node(root, parent, ptr);
    }
    return root;
}

void preorder_traversal(suhani *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(suhani *root)
{
    if (root != NULL)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d\t", root->data);
    }
}

void inorder_traversal(suhani *root)
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
    suhani *root = createlist();

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