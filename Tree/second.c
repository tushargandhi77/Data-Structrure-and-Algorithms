#include"stdio.h"
#include"stdlib.h"

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int val){
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insertleft(struct node *root,int val){
    root->left = create_node(val);
    return root->left;
}

struct node *insertright(struct node *root,int val){
    root->right = create_node(val);
    return root->right;
}

void preorder_traversal(struct node *root){
    if(root!=NULL){
    printf("%d\t",root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
    }
}

void postorder_traversal(struct node *root){
    if(root!=NULL){
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d\t",root->data);
    }
}

void inorder_traversal(struct node *root){
    if(root!=NULL){
        inorder_traversal(root->left);
        printf("%d\t",root->data);
        inorder_traversal(root->right);
    }
}

int main(){
    struct node *root = create_node(1);
    insertleft(root,12);
    insertright(root,9);

    insertleft(root->left ,5);
    insertright(root->left,6);

    printf("\n preorder traversal \n");
    preorder_traversal(root);

    printf("\n Inorder traversal \n");
    inorder_traversal(root);

    printf("\n postorder traversal \n");
    postorder_traversal(root);

}