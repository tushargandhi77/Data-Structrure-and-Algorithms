#include"stdio.h"
#include"stdlib.h"

struct node {
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int getheight(struct node *n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

struct node *createnode(int key){
    struct node *new = (struct node *)malloc(sizeof(struct node));

    new->key = key;
    new->left = NULL;
    new->right = NULL;
    new->height = 1;
    return new;
}

int max(int a,int b){
    return (a>b)?a:b;
}

int getbalancefactor(struct node *n){
    if(n==NULL){
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}

struct node *rightrotates(struct node *y){
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getheight(x->right),getheight(x->left)) + 1;
    y->height = max(getheight(y->right),getheight(y->left)) + 1;

    return x;
}

struct node *leftrotates(struct node *x){
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getheight(x->right),getheight(x->left)) + 1;
    y->height = max(getheight(y->right),getheight(y->left)) + 1;

    return y;
}

struct node *insert(struct node * node,int key){
    if(node == NULL){
        return createnode(key);
    }
    if(key < node->key){
        node->left = insert(node->left,key);
    }
    else if(key > node->key){
        node->right = insert(node->right,key);
    }
    node->height = 1 + max(getheight(node->left),getheight(node->right));
    int bf = getbalancefactor(node);

    if(bf>1 && key < node->left->key){
        return rightrotates(node);
    }
    if(bf<-1 && key > node->right->key){
        return leftrotates(node);
    }
    if(bf>1 && key > node->left->key){
        node->left = leftrotates(node->left);
        return rightrotates(node);
    }
    if(bf<-1 && key < node->right->key){
        node->right = rightrotates(node->right);
        return leftrotates(node);
    }
    return node;
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("\t%d",root->key);
        inorder(root->right);
    }
}

int main(){
    struct node *root = NULL;

    root = insert(root,1);
    root = insert(root,19);
    root = insert(root,39);
    root = insert(root,5);
    root = insert(root,10);
    root = insert(root,25);
    
    inorder(root);
}

