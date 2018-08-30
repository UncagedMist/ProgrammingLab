#include <stdio.h>

int main()
{
    int row, col, i, j, count=0;
    int matrix[50][50];
    
    printf("Enter Rows and Columns of Matrix\n");
    scanf("%d %d", &row, &col);
      
    printf("Enter Matrix of size %dX%d\n", row, col);
    
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(matrix[i][j] == 0)
            {
             count++;
            }
        }
    }
    
    if(count > (row*col)/2)
    {
        printf("Given Matrix is a Sparse Matrix\n");
    } 
    else 
    {
        printf("Given Matrix is Not a Sparse Matrix\n");
    }
    
    return 0;
}
