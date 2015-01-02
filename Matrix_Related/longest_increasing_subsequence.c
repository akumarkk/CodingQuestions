/* Longest Increasing Subsequence of n can be found by lis(n-1) 
 */
#include <stdio.h>
#include <string.h>

int
longest_increasing_subsequence(char *str)
{
    int	    i, j;
    int	    max = 0;
    int	    len = strlen(str);
    int	    lis[len];

    if(str == NULL || len == 0)
	return -1;

    lis[0] = 1;
    for(i=1; i<len; i++)
    {
	lis[i] = 1;
	for(j=0; j<i; j++)
	{
	    if(str[i] > str[j] && ( (lis[j] +1) > lis[i]))
		lis[i] = lis[j] + 1;
	    if(max < lis[i])
		max = lis[i];
	}
    }

    return max;
}

int
main()
{
    int	 max=0;
    char str[100];
    printf("String : ");
    scanf("%s", str);

    max = longest_increasing_subsequence(str);
    printf("Length of longest increasing subsequence	:   %d\n", max);

    return max;
}
