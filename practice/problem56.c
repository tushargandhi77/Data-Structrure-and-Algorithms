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

void merge(int *arr,int mid,int low,int high){
    int i,j,k;
    i = low;
    j = mid + 1;
    k = low;
    int b[100];
    while(i<=mid && j<=high){
        if(arr[i] < arr[j]){
            b[k] = arr[i];
            i++;
            k++;
        }
        else{
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        b[k] = arr[i];
        i++;
        k++;
    }
    while(j<=high){
        b[k] = arr[j];
        j++;
        k++;
    }
    for(i=low;i<=high;i++){
        arr[i] = b[i];
    }
}

void mergearray(int *arr,int low,int high){
    int mid;
    if(low<high){
        mid = (low+high)/2; 
        mergearray(arr,low,mid);
        mergearray(arr,mid+1,high);
        merge(arr,mid,low,high);
    }
}

int main()
{
    int arr[100], n, key;
    printf("Enter the size of array:");
    scanf("%d", &n);
    input(arr, n);
    display(arr, n);
    mergearray(arr,0,n-1);
    display(arr, n);
}