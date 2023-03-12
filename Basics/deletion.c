#include"stdio.h"
void input(int *,int );
void display(int *,int);
void delete(int *,int ,int);
int main(){
    int arr[100],pos,n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    input(arr,n);
    printf("Enter the position where you want to delete:");
    scanf("%d",&pos);
    display(arr,n);
    delete(arr,n,pos);
    printf("\nThe array  after deletion:\n");
    display(arr,n-1);
    return 0;
}
void input(int *arr,int n){
    int i;
    printf("Enter the element of array:");
    for(i=0;i<n;i++){
        scanf("%d",(arr+i));
    }
}
void display(int *arr,int n){
    int i;
    printf("\nThe array is :\n");
    for(i=0;i<n;i++){
        printf("%d\t",*(arr+i));
    }
}
void delete(int *arr,int n,int pos){
    int i;
    for(i=pos-1;i<n-1;i++){
        *(arr+i)=*(arr+i+1);
    }
}