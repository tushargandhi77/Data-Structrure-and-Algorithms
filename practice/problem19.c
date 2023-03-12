#include"stdio.h"
#include"stdlib.h"

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int val){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = val;
}

struct node *insertleft(struct node *root,int val){
        root->left = createnode(val);
        return root->left;
}

struct node *insertright(struct node *root,int val){
    root->right = createnode(val);
    return root->right;
}

void pretraversal(struct node *root){
    if(root!=NULL){
    printf("\t%d",root->data);
    pretraversal(root->left);
    pretraversal(root->right);
    }
}

void posttraversal(struct node *root){
    if(root!=NULL){
        posttraversal(root->left);
        posttraversal(root->right);
        printf("\t%d",root->data);
    }
}

void inordertraversal(struct node *root){
    if(root!=NULL){
        inordertraversal(root->left);
        printf("\t%d",root->data);
        inordertraversal(root->right);
    }
}

int main(){

    struct node * root = createnode(2);

    insertleft(root,4);
    insertright(root,10);

    insertleft(root->left,6);
    insertright(root->left,8);

    insertleft(root->left->left,14);
    insertright(root->left->left,18);

    printf("The preordertraversal:\n");
    pretraversal(root);

    printf("\nThe postordertraversal:\n");
    posttraversal(root);

    printf("\nThe INordertraversal:\n");
    inordertraversal(root);
}