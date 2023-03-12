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
int  binarysearch(int *arr,int n,int key){
    int i,mid;
    int start = 0;
    int end = n-1;
    for(i=0;i<n;i++){
        mid = (start+end)/2;
        if(key == arr[mid]){
            return mid;
        }
        else if(key > arr[mid]){
            start = mid +1;
        }
        else{
            end = mid - 1;
        }
    }
}
int main()
{
    int arr[100], n, key;
    printf("Enter the size of array:");
    scanf("%d", &n);
    input(arr, n);
    display(arr, n);
    printf("Enter the element to search:");
    scanf("%d",&key);
    printf("The element %d found at %d",key,binarysearch(arr,n,key)+1);
}