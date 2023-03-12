#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} suhani;

suhani *createnode(int val)
{
    suhani *newnode = (suhani *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("memory not allocated!");
        exit(0);
    }
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

suhani *insert(suhani *root)
{
    int val;
    suhani *newnode, *ptr, *parent;
    printf("Enter the data to insert:");
    scanf("%d", &val);

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
            parent = ptr;
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
                printf("dublicate value!");
            }
        }
        if (parent->data > val)
        {
            parent->left = newnode;
        }
        else
        {
            parent->right = newnode;
        }
    }
    return root;
}

suhani *createlist()
{
    suhani *root = NULL;
    int i, n;
    printf("Enter no of nodes:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        root = insert(root);
    }
    return root;
}

suhani *del_no_child(suhani *root, suhani *parent, suhani *ptr)
{
    if (parent == NULL)
    {
        root = NULL;
    }
    else if (parent->left == ptr)
    {
        parent->left = NULL;
    }
    else if (parent->right == ptr)
    {
        parent->right = NULL;
    }
    free(ptr);
    return root;
}

suhani *del_one_child(suhani *root, suhani *parent, suhani *ptr)
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

suhani *del_two_child(suhani *root, suhani *parent, suhani *ptr)
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
        root = del_one_child(root, p_successor, successor);
    }
    else
    {
        root = del_no_child(root, p_successor, successor);
    }
    free(ptr);
    return root;
}

suhani *delete (suhani *root)
{
    suhani *ptr = NULL, *parent = NULL;
    int data;
    printf("Enter the data to be delete:");
    scanf("%d", &data);

    ptr = root;
    while (ptr != NULL)
    {
        if (ptr->data == data)
        {
            break;
        }
        parent = ptr;
        if (ptr->data > data)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = ptr->right;
        }
    }
    if (ptr->left != NULL && ptr->right != NULL)
    {
        root = del_two_child(root, parent, ptr);
    }
    else if (ptr->left != NULL || ptr->right != NULL)
    {
        root = del_one_child(root, parent, ptr);
    }
    else
    {
        root = del_no_child(root, parent, ptr);
    }
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