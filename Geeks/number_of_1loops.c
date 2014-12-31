#include <stdio.h>
#define DEBUG	0 
#define debug(fmt, ...)\
    do{\
	if(DEBUG)\
	    fprintf(stdout, "%s(%d) :" fmt, __FUNCTION__, __LINE__, __VA_ARGS__);\
    }while(0)

int
number_of_1sloop(int *a, int n)
{
    int i, count=0, count_1 = 0;
    for(i=0; i<n; i++)
    {
	if(a[i] == 1)
	{
	    count_1++;

	    if(count_1 == 2)
		count = 1;
	    else if(count_1 > 2)
	    {
		count+= (count_1 - 1);
		debug("i=%d count_1 = %d	count = %d\n", i, count_1, count);
	    }
	}
    }

    return count;
}

int
main()
{
    int a[100], n, i;

    printf("Size of array :");
    scanf("%d", &n);

    printf("Items : ");
    for(i=0; i<n; i++)
	scanf("%d", &a[i]);

    i = number_of_1sloop(a, n);
    printf("Number of loops starts and ends with 1 = %d\n", i);
    return 0;
}
