#include"stdio.h"
#include"stdlib.h"
void input(int *,int);
void display(int *,int);
void lsearch(int *,int,int);

int main(){
    int arr[100],n,key;
    printf("Enter the size of array:");
    scanf("%d",&n);
    input(arr,n);
    printf("Enter the element which you want to search:");
    scanf("%d",&key);
    display(arr,n);
    lsearch(arr,n,key);
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
    printf("\nThe element of array:\n");
    for(i=0;i<n;i++){
        printf("\t%d",*(arr+i));
    }
    printf("\n");
}
void lsearch(int *arr,int n,int key){
    int i;
    for(i=0;i<n;i++){
        if(*(arr+i)==key){
            printf("The element found in the array:At position %d\n",i+1);
            exit(0);
        }
    }
    printf("Element not found!");
}