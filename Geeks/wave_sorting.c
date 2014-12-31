#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define swap(a, b) \
    do{\
	a = a ^ b;\
	b = a ^ b;\
	a = a ^ b; \
    }while(0);

int
wave_sort(int *a, int n)
{
    int i=0; 

    for(i=0; i<n-1; i++)
    {
	if(i%2 == 0)
	{
	    /* Even indices */
	    if(a[i] > a[i+1])
		swap(a[i], a[i+1]);
	}
	else
	{
	    if(a[i] < a[i+1])
		swap(a[i], a[i+1]);
	}
    }
    return 0;
}

void
print_array(int *a, int n)
{
    int i=0;
    for(i=0; i<n; i++)
	printf("%d   ", a[i]);
    printf("\n------ END --------\n");
}

int
main()
{
    int a[100], n, i;
    printf("Size of array :");
    scanf("%d", &n);

    printf("Array ITEMS : ");
    for(i=0; i<n; i++)
	scanf("%d", &a[i]);

    wave_sort(a, n);
    print_array(a, n);
    return 0;
}

