#include"stdio.h"
void input(int *, int);
void display(int *, int);
int binarysearch(int *,int,int);

int main(){
    int arr[100],n,key,val;
    printf("Enter the size of array:");
    scanf("%d",&n);
    input(arr,n);
    printf("Enter the value which you want to search:");
    scanf("%d",&key);
    display(arr,n);
    val = binarysearch(arr,n,key);
    if(val>n-1){
        printf("\nnot found\n");
    }
    else
    {    
    printf("\nThe value is present at the position:%d\n",val+1);
    }
    return 0;

}
void input(int *arr, int n)
{
    int i;
    printf("Enter the Assending sorted array element of array:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
}
void display(int *arr, int n)
{
    int i;
    printf("\nThe array is :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", *(arr + i));
    }
}
int binarysearch(int *arr,int n,int key){
    int i,mid,start,end;
    start = 0;
    end = n-1;
    for(i=0;i<n;i++){
        mid = (start+end)/2;
        if(*(arr+mid)==key){
            return mid;
        }
        else if(*(arr+mid)<key){
            start = mid+1;
        }
        else if (*(arr+mid)>key){
            end = mid-1;
        }
    }
}