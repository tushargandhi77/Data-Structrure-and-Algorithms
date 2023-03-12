#include"stdio.h"
void input(int *,int);
void display(int *,int);
int bsearch(int *,int,int);

int main(){
    int a[100],n,key,pos;
    printf("Enter the size of array:");
    scanf("%d",&n);
    input(a,n);
    printf("Enter the element which you want to search:");
    scanf("%d",&key);
    display(a,n);
    pos = bsearch(a,n,key);
    if(pos+1>n){
        printf("element not found!\n");
    }
    else
    {
        printf("Element found ! At the position:%d\n",pos+1);
    }
    
    return 0;
}
void input(int *arr,int n){
    int i;
    printf("Enter the element of sorted array:");
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
int bsearch(int *arr,int n,int key){
    int i,mid,start,end;
    start = 0;
    end = n-1;
    for(i=0;i<n;i++){
        mid = (start+end)/2;
        if(*(arr+mid)==key){
            return mid;
        }
        if(*(arr+mid)>key){
            end = mid - 1 ;
        }
        if(*(arr+mid)<key){
            start = mid + 1;
        }
    }
}