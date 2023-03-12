#include "stdio.h"
#include "stdlib.h"

struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};
void createarray(struct myarray *a, int tsize, int usize)
{
    (*a).total_size = tsize;
    (*a).used_size = usize;
    (*a).ptr = (int *)malloc(tsize * sizeof(int));
}
void show(struct myarray *a)
{
    printf("\nThe element of the array:\n");
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\t", (a->ptr)[i]);
    }
}
void setvalue(struct myarray *a)
{
    printf("Enter the element of the array:");
    for (int i = 0; i < a->used_size; i++)
    {
        scanf("%d", &(a->ptr)[i]);
    }
}

int main(int argc, char const *argv[])
{
    struct myarray marks;
    createarray(&marks, 10, 6);
    setvalue(&marks);
    show(&marks);
    return 0;
}
