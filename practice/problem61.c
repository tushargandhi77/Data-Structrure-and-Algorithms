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

int  partition(int *arr,int low,int high){
    int i ,j,key;
    key = arr[low];
    i = low+1;
    j = high;
    int temp;
    do{
        while(arr[i]<=key){
            i++;
        }
        while(arr[j]>key){
            j--;
        }
        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i<j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quicksort(int *arr,int low,int high){
    int par;
    if(low<high){
        par = partition(arr,low,high);
        quicksort(arr,low,par-1);
        quicksort(arr,par+1,high);
    }
}

int main()
{
    int arr[100], n, key;
    printf("Enter the size of array:");
    scanf("%d", &n);
    input(arr, n);
    display(arr, n);
    quicksort(arr,0,n-1);
    display(arr, n);

}