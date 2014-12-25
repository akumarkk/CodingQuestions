#include <stdio.h>
#include <stdlib.h>

int
get_biggest_sequence(int *a, int n, int *start)
{
    int max_count=1, count=1, pos=0, max_pos=0;
    int i =0;


    for(i=1; i<n; i++)
    {
	if(a[i] > a[i-1])
	{
	    count++;
	}
	else
	{
	    if(max_count < count)
	    {
		max_count = count;
		max_pos = pos;
	    }
	    count = 1;
	    pos = i;
	}
    }
    if(max_count < count)
    {
	max_count = count;
	max_pos = pos;
    }

    *start = pos;
    return max_count;
}


int
main()
{
    int i, a[100], n;
    int count=0, start=0;

    printf("# of items : ");
    scanf("%d", &n);

    printf("Typein items : ");
    for(i=0; i<n; i++)
    {
	scanf("%d", &a[i]);
    }

    count = get_biggest_sequence(a, n, &start);
    printf("Biggest sequence : %d\n", count);

    for(i=0; i<count; i++)
	printf("%d   ", a[start+i]);

    printf("\n");
    return 0;
}
