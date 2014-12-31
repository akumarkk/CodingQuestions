/* Sort an array in wave form
 * Given an unsorted array of integers, sort the array into a wave like array. An array ‘arr[0..n-1]’ is sorted in wave form if arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..
 *
 * Examples:
 *
 *  Input:  arr[] = {10, 5, 6, 3, 2, 20, 100, 80}
 *   Output: arr[] = {10, 5, 6, 2, 20, 3, 100, 80} OR
 *                    {20, 5, 10, 2, 80, 6, 100, 3} OR
 *                                     any other array that is in wave form
 *
 *
 * Solution :
 * This can be done in O(n) time by doing a single traversal of given array. The idea is based on the fact that if we make sure that all even positioned (at index 0, 2, 4, ..) elements are greater than their adjacent element, we don’t need to worry about odd positioned element. Following are simple steps.
 * 1) Traverse all even positioned elements of input array, and do following.
 * ….a) If current element is smaller than previous element, swap previous and current.
 * ….b) If current element is smaller than next element, swap next and current.
 *
 */
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

