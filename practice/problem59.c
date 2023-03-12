#include"stdio.h"
#include"stdio.h"

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

void selectionsort(int *arr,int n){
    int i,j,pos,min,temp;
    for(i=0;i<n-1;i++){
        min = *(arr+i);
        pos = i;
        for(j=i+1;j<n;j++){
            if(*(arr+j)<min){
                min = *(arr+j);
                pos = j;
            }
        }
        if(pos!=i){
            temp = *(arr+pos);
            *(arr+pos) = *(arr+i);
            *(arr+i) = temp;
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
    selectionsort(arr,n);
    display(arr, n);

}