#include <stdio.h>
#include <stdlib.h>


void print_array(int *a, int n);

int
get_frequency(int *a, int n, int key)
{
    int count = 0;
    int low=0, high=n-1;
    int mid, i;


    while(low <= high)
    {
	mid = (low + high)/2;
	if(a[mid] == key)
	    break;
	else if (key > a[mid])
	    low  = mid+1;
	else 
	    high = mid - 1;
    }

    if(a[mid] == key)
    {
	count = 1;
	for(i=mid+1; i<n; i++)
	{
	    if(a[i] == key)
		count++;
	    else
		break;
	}

	for(i=mid-1; i>=0; i--)
	{
	    if(a[i] == key)
		count++;
	}
    }

    return count;
}


#define swap(a, b) { \
    if(a != b){\
	a = a ^ b;\
	b = a ^ b;\
	a = a ^ b;\
    }\
}

int
heapify(int *a, int start, int n)
{
    int lchild, rchild, largest;
    int end = (n-1)/2;

    while(start <= end)
    {
	lchild = 2*start + 1;
	rchild = 2*start + 2;
	if(rchild <= n)
	{
	    if(a[rchild] > a[lchild])
		largest = rchild;
	    else
		largest = lchild;

	}
	else
	    largest = lchild;

	if(a[start] < a[largest])
	{
	    swap(a[start], a[largest]);
	    start = largest;
	}
	else
	    break;
    }

    return 0;
}

int
build_max_heap(int *a, int n)
{
    for(int i = (n-1)/2; i>=0; i--)
	heapify(a, i, n);

    return 0;
}


   
 int
sort_set(int *a, int n)
{
    int i, tmp;

    for(i=n-1; i>0;i--)
    {
	build_max_heap(a, i);
	swap(a[i], a[0]);
    }

    printf("SORTED ARRAY : \n");
    print_array(a, n);
    return 0;
}

void
print_array(int *a, int n)
{
    for(int i=0; i<n; i++)
	printf("%d ", a[i]);
    printf("\n");
}

static int m;
int **
get_intersection(int **a, int num_sets, int *size)
{
    int i=0, j=0;
    int k, count, minset, minsize;
    int **tmp;

    minset = 0;
    minsize = size[0];

    for(i=0; i<num_sets; i++)
    {
	if(minsize > size[i])
	{
	    minset = i;
	    minsize = size[i];
	}

	sort_set(a[i], size[i]);
    }


    tmp = malloc(2 * sizeof(int *));
    tmp[0] = malloc(sizeof(int) * minsize);
    tmp[1] = malloc(sizeof(int) * minsize);

    count = 1;
    k = 0;
    tmp[0][k] = a[minset][0];

    printf("Redundancy processing on minset(%d) ...\n", minset);

    for(i=1; i<size[minset]; i++)
    {
	if(a[minset][i] == a[minset][i-1])
	    count++;
	else
	{
	    tmp[1][k] = count;
	    tmp[0][++k] = a[minset][i];
	    count = 1;
	}
    }
    tmp[1][k] = count;
    for(int z=0; z<size[minset]; z++)
	printf("%d[%d]   ", tmp[0][z], tmp[1][z]);
    printf("\n");


     m=0;
     for(i=0; i<=k; i++)
     {
	 printf("k = %d\n", i);
	 printf("\nProcessing item : %d\n", tmp[0][i]);
	 for(j=0; j<num_sets; j++)
	 {
	     printf("Processing set(%d) ...\n", j);
	     if( minset != j )
	     {
		 printf("YES, PROCESS\n");

		count = get_frequency(a[j], size[j], tmp[0][i]);
		printf("Frequency of %d in set %d = %d\n", tmp[0][i], j, count);

		if(count == 0)
		    break;
		else 
		{
		    if(count < tmp[1][i])
			tmp[1][i] = count;
		}
	     }
	}
	 if(j == num_sets)
	 {
	    printf("ADDED %d at %d into FINAL LIST\n", tmp[0][i], m);
	     tmp[0][m] = tmp[0][i];
	     tmp[1][m] = (count < tmp[1][i])?count: tmp[1][i];
	     m++;
	 }
     }

     return tmp;
}


int
main()
{
    int n, **a, size[100];
    int **tmp, i;

    printf("# of sets : ");
    scanf("%d", &n);

    a = malloc(sizeof(int *) * n);

    for(i=0; i<n; i++)
    {
	printf("Size : ");
	scanf("%d", &size[i]);

	a[i] = malloc(sizeof(int) * size[i]);
	printf("Members of the set : ");
	for(int j=0; j<size[i]; j++)
	    scanf("%d", &a[i][j]);
    }

    tmp = get_intersection(a, n, size);
   
    printf("Intersetion of sets : "); 
    for(i=0; i<m; i++)
	printf("%d[%d]  ", tmp[0][i], tmp[1][i]);
    
    printf("\n");
    return 0;
}
	    

