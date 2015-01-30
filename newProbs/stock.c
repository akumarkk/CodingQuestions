/*
 * Write a function to return the best pair of trades to maximize profit. The buy must occur before the sell.
 */
#include <stdio.h>

int min_index;
int max_index;
int min;

int
max_profit(int *a, int n)
{
    int i=0;
    int max_profit_so_far = 0;
    int min_so_far = a[0];

    for(i=1; i<n; i++)
    {
	if(min_so_far > a[i])
	{
	    min_so_far = a[i];
	    min_index = i;
	}

	if(max_profit_so_far < (a[i] - min_so_far))
	{
	    max_index = i;
	    min = min_index;
	    max_profit_so_far = a[i] - min_so_far;
	}
    }

    return max_profit_so_far;
}

int
main()
{
    int a[256], n;

    printf("# of items : ");
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
	scanf("%d", &a[i]);
    }

    n = max_profit(a, n);
    printf("Max profit = %d	(min, max) = (%d, %d)\n", n, a[min], a[max_index]);

    return 0;
}

