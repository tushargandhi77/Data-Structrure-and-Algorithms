#include"stdio.h"
#include"stdlib.h"

void input(int *arr,int n){
    printf("\nEnter the array element:\n");
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void display(int *arr,int n){
    printf("\nThe array:\n");
    int i;
    for(i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    printf("\n");
}

void insertionisort(int *arr,int n){
    int i,j;
    int key;
    for(i=1;i<=n-1;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[100],n,key;
    printf("Enter the size of array:");
    scanf("%d",&n);
    input(arr,n);
    display(arr,n);
    insertionisort(arr,n);
    display(arr,n);
}