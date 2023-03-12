#include"stdio.h"
#include"malloc.h"

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int val){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main(){

    struct node *p = create_node(3);
    struct node *p1 = create_node(45);
    struct node *p2 = create_node(22);

    p->left = p1;
    p->right = p2;

    return 0;

}