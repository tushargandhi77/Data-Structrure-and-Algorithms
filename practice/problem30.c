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
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
}

int getheight(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
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
    return getheight(root->left) - getheight(root->right);
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
        return createnode(val);
    }
    if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    if (val == root->data)
    {
        printf("same element not to be input\n");
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

struct node *create_list(){
    struct node *root = NULL;
    int n,i,data;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter the in AVL tree:");
        scanf("%d",&data);
        root = insert(root,data);
    }
    return root;
}
void inordertraversal(struct node *root){
    if(root!=NULL){
        inordertraversal(root->left);
        printf("\t%d",root->data);
        inordertraversal(root->right);
    }
}
int main(){
    struct node *root = create_list();
    inordertraversal(root);
}