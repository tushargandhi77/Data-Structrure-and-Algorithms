#include"stdio.h"
void input(int *,int);
void display(int *,int);
void sort(int*,int);
int main(){
    int arr[100],n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    input(arr,n);
    printf("\nThe array:\n");
    display(arr,n);
    printf("\nThe sorted array:\n");
    sort(arr,n);
    display(arr,n);
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
    for(i=0;i<n;i++){
        printf("%d\t",*(arr+i));
    }
    printf("\n");
}
void sort(int *arr,int n){
    int i,j,pos,temp,min;
    for(i=0;i<n-1;i++){
        min=*(arr+i);
        pos=i;
        for(j=i+1;j<n;j++){
            if(*(arr+j)<min){
                min = *(arr+j);
                pos=j;
            }
            if(pos!=i){
                temp = *(arr+pos);
                *(arr+pos) = *(arr+i);
                *(arr+i) = temp;
            }
        }
    }
}