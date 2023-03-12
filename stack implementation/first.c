#include"stdio.h"
#include"stdlib.h"

struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    struct stack *s;
    s->size=6;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));
    
    s->arr[0]=4;
    s->top++;
    s->arr[1]=2;
    s->top++;
    s->arr[2]=7;
    s->top++;
    s->arr[3]=11;
    s->top++;
    s->arr[4]=7;
    s->top++;
    s->arr[5]=1;
    s->top++;
    
    // printf("Enter the element of stack!");
    // for(int i=0;i<6;i++){
    //     scanf("%d",s->arr[i]);
    //     s->top++;
    // }

    if(isEmpty(s)){
        printf("stack is empty!\n");
    }
    else{
        printf("stack is not empty!\n");
    }
    if(isFull(s)){
        printf("Stack is full\n");
    }
    else{
        printf("stack is  not full\n");
    }
}