#include "stdio.h"
#include "stdlib.h"

int f ;
int r ;
int size;
int arr[100];

int isfull()
{
    if (r == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty()
{
    if (f == r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enequeue(int data)
{
    if (isfull())
    {
        printf("\nQueue overflow\n");
    }
    else
    {
        r++;
        arr[r] = data;
    }
}

int dequeue()
{
    int data = -1;
    if (isempty())
    {
        printf("\nQueue underflow\n");
    }
    else
    {
        f++;
        data = arr[f];
    }
    return data;
}

void traversal(){
    int i;
    printf("\nThe queue:\n");
    for(i=f;i<r;i++){
        printf(" %d ",arr[i+1]);
    }
}

int main(){
    int x,data;
    f = r = -1;
    printf("Enter the size of queue:");
    scanf("%d",&size);
    while(1){
        printf("\nEnter 1 for enque\nEnter 2 for dequeue\nEnter 3 for traversal\nEnter 4 for exit\n");
        scanf("%d",&x);
        switch (x)
        {
        case 1:
            printf("Enter data to enqueue:");
            scanf("%d",&data);
            enequeue(data);
            break;
        case 2:
            printf("The dequeue element:%d\n",dequeue());
            break;
        case 3:
            traversal();
            break;
        case 4:
            exit(0);
            break;
        default:
            break;
        }
    }
}