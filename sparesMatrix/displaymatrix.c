#include "stdio.h"
void input_spares(int, int, int[][100]);
void display_spares(int, int, int[][100]);
void display_triplet(int, int, int[][100], int[][3]);
int main()
{
    int arr[100][100], r, c, res[100][3];
    printf("Enter the row and column:");
    scanf("%d%d", &r, &c);
    input_spares(r, c, arr);
    display_spares(r, c, arr);
    display_triplet(r, c, arr, res);
    return 0;
}
void input_spares(int r, int c, int a[100][100])
{
    int i, j;
    printf("Enter the spares matrix");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}
void display_spares(int r, int c, int a[100][100])
{
    int i, j;
    printf("\nThe spares matrix:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
void display_triplet(int r, int c, int a[100][100], int res[100][3])
{
    int i, j, k = 1, nz = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                nz++;
            }
        }
    }
    res[0][0] = r;
    res[0][1] = c;
    res[0][2] = nz;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                res[k][0] = i;
                res[k][1] = j;
                res[k][2] = a[i][j];
                k++;
            }
        }
    }
    printf("\nThe triplet matrix:\n");
    for (i = 0; i < res[0][2]+1; i++)
    {
        for (j = 0; i < 3; j++)
        {
            printf("\t%d", res[i][j]);
        }
    }
}