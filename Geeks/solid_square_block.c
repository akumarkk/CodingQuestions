#include <stdio.h>
#define DEBUG 1
#define debug(fmt, ...)\
do{\
    if(DEBUG)\
	fprintf(stdout, "%s(%d):" fmt, __FUNCTION__, __LINE__, __VA_ARGS__);\
	    fflush(stdout);\
}while(0)



void
print_matrix(int m, int n, int a[m][n])
{
    int i, j;
    for(i=0; i<m; i++)
    {
	for(j=0; j<n; j++)
	    printf("%d   ", a[i][j]);
	printf("\n");
    }
}

int minimum(int a, int b, int c) 
{
    int min = a;
	if(min > b)
	    min = b;
	if(min > c)
	    min = c;
	return min;
}

    
int
solid_square_block(int a[100][100], int m, int n, int *row, int *col)
{
    int i=0, j=0, max;
    int matrix[m][n];

    for(i=0; i<m; i++)
    {
	for(j=0; j<n; j++)
	{
	    if(i==0 || j==0)
		matrix[i][j] = a[i][j];
	    else if(a[i][j] == 1)
	       matrix[i][j]= minimum(matrix[i][j-1], matrix[i-1][j], matrix[i-1][j-1])  + 1; 	
	    else
		matrix[i][j] = 0;
	    debug("i=%d	j=%d	value = %d\n", i, j, matrix[i][j]);
	}
    }

    printf("Constructed matrix	: \n");
    print_matrix(m, n, matrix);

    max = 1;
    debug("Matrix constructed with max = %d\n", max);

    for(i=0; i<m; i++)
    {
	for(j=0; j<n; j++)
	{
	    if(matrix[i][j] > 1)
	    {
		max = matrix[i][j];
		*row = i;
		*col = j;
	    }
	}
    }

    return max*max;
}




int
main()
{
    int max=0;
    int i, j, m, n, a[100][100];

    printf("Number of rows and col : ");
    scanf("%d%d", &m, &n);

    printf("Matrix contents : ");
    for(i=0; i<m; i++)
	for(j=0; j<n; j++)
	    scanf("%d", &a[i][j]);

    max = solid_square_block(a, m, n, &i, &j);
    printf("Max solid square block area	    : %d\n", max);
    printf("row = %d	col = %d\n", i, j);

    return 0;
}
