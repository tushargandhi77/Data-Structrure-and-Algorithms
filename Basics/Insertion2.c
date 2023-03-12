#include<stdio.h>


int main(){
    int arr[100],n,pos,val;
    printf("Enter the size of array:\n");
    scanf("%d",&n);

    printf("Enter the element of array:\n");
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }


    printf("Enter position of insertion:\n");
    scanf("%d",&pos);
    printf("Enter the value of element which you have to insert:");
    scanf("%d",&val);
    if(pos>n){
        printf("Not possible");
        return 0;
    }


    printf("Array before insertion:\n");
    for(int i = 0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");

    // Insertion
    for(int i=n-1;i>=pos-1;i--){
        arr[i+1] = arr[i];
    }
    arr[pos-1] = val;

    //print array
    printf("Array After insertion:\n");
    for(int i = 0;i<n+1;i++){ // n+1 because after insertion one element increases
        printf("%d\t",arr[i]);
    }
    printf("\n");

}