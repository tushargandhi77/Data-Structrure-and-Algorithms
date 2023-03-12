#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
};

struct node *createnode(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("memory not allocated");
        exit(0);
    }
    newnode->data = val;
    newnode->height = 1;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int getheight(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int balancefactor(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return getheight(root->left) - getheight(root->right);
    }
}

struct node *search(struct node *root, int val)
{
    if (root == NULL)
    {
        printf("Element not found\n");
        return NULL;
    }
    if (root->data == val)
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

struct node *rightrotates(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = 1 + max(getheight(x->left), getheight(x->right));
    y->height = 1 + max(getheight(y->left), getheight(y->right));

    return x;
}

struct node *leftrotates(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getheight(x->left), getheight(x->right));
    y->height = 1 + max(getheight(y->left), getheight(y->right));

    return y;
}
struct node *insert(struct node *root, int val)
{
    if (root == NULL)
    {
        root = createnode(val);
    }
    if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }

    root->height = 1 + max(getheight(root->left), getheight(root->right));

    int bf = balancefactor(root);

    if (bf > 1 && val < root->left->data)
    {
        return rightrotates(root);
    }
    if (bf < -1 && val > root->right->data)
    {
        return leftrotates(root);
    }
    if (bf > 1 && val > root->left->data)
    {
        root->left = leftrotates(root->left);
        return rightrotates(root);
    }
    if (bf < -1 && val < root->right->data)
    {
        root->right = rightrotates(root->right);
        return leftrotates(root);
    }

    return root;
}

struct node *createlist()
{
    struct node *root = NULL;
    int i, x, d;
    printf("Enter the number of nodes:");
    scanf("%d", &x);
    for (i = 0; i < x; i++)
    {
        printf("Enter the data:");
        scanf("%d", &d);
        root = insert(root, d);
    }
    return root;
}

void maximum(struct node *root)
{
    struct node *ptr = root;
    while (ptr->right != NULL)
    {
        ptr = ptr->right;
    }
    printf("The maximum in root:%d\n", ptr->data);
}

void minimum(struct node *root)
{
    struct node *ptr = root;
    while (ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    printf("The minimum in root:%d\n", ptr->data);
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
void inordertraversal(struct node *root)
{
    if (root != NULL)
    {
        inordertraversal(root->left);
        printf(" %d ", root->data);
        inordertraversal(root->right);
    }
}

int main()
{
    struct node *root = createlist();

    int x, y, z, k;
    while (1)
    {
        printf("\nEnter 1 for Avl insert\nEnter 2 for Avl treesearch\nEnter 3 for maximum in Avl tree\nEnter 4 for minimum in Avl tree\nEnter 5 for preordertraversal\nEnter 6 for postordertraversal\nEnter 7 for inordertravresal\nEnter 8 for exit\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            printf("Enter data to insert in Avl:");
            scanf("%d", &y);
            root = insert(root, y);
            printf("\n");
            break;
        case 2:
            printf("Enter data to be search in Avl bst:");
            scanf("%d", &z);
            struct node *n = search(root, z);
            break;
        case 3:
            printf("\n");
            maximum(root);
            break;
        case 4:
            printf("\n");
            minimum(root);
            break;
        case 5:
            printf("\nThe preordertraversal:\n");
            preordertraversal(root);
            printf("\n");
            break;
        case 6:
            printf("\nThe postordertraversal:\n");
            postordertraversal(root);
            printf("\n");
            break;
        case 7:
            printf("\nThe inordertraversal:\n");
            inordertraversal(root);
            printf("\n");
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("\nEnter valid input\n");
            break;
        }
    }
}