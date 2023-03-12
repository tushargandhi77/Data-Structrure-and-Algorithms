#include"stdio.h"
#include"stdlib.h"

void input(int *arr,int n){
    printf("\nEnter the data:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void display(int *arr,int n){
    printf("\nEnter the data:\n");
    for(int i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
}

void insertionsort(int *arr,int n){
    int key,j;
    for(int i=1;i<=n-1;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j] >= key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


int main()
{
    int arr[100], n, key;
    printf("Enter the size of array:");
    scanf("%d", &n);
    input(arr, n);
    display(arr, n);
    insertionsort(arr,n);
    display(arr, n);
}