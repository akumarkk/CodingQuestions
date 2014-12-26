#include <stdio.h>

#define swap(a, b) {\
    a = a ^ b;\
    b = a ^ b;\
    a = a ^ b;\
}


int
get_k_largest_items(int *a, int n, int k)
{
    int i, j;

    if(k > n)
	return -1;

    for(i=k; i<n; i++)
    {
	for(j=0; j<k; j++)
	{
	    if(a[j] < a[i])
		swap(a[j], a[i]);
	}
    }

    return 0;
}


int
main()
{
    int i=0;
    int k, n, a[100];

    printf("# of items ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
	scanf("%d", &a[i]);

    printf("Value of K : ");
    scanf("%d", &k);

    get_k_largest_items(a, n, k);

    printf("K Largest items : ");
    for(i=0; i<k; i++)
	printf("%d   ", a[i]);
    printf("\n");

    return 0;
}
