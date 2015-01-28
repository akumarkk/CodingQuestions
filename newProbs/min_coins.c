#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>

int den[] = {1, 5, 10, 20, 25};

int
min_coins(int n)
{
    int i, j;
    int coins[n+1];

    if(n == 0)
	return 0;

    for(i=0; i<=n; i++)
	coins[i] = INT_MAX - 1;

    coins[0] = 0;
    for(i=1; i<=n; i++)
    {
	for(j=0; j<5; j++)
	{
	    if( (i>=den[j]) && (coins[i- den[j]] + 1) < coins[i])
		coins[i] = coins[i- den[j]] + 1;
	}
    }
    
    printf("coins[%d] = %d\n", n, coins[n]);
    printf("coins[%d] = %d\n", n-1, coins[n-1]);
    return coins[n];
}


int
main()
{
    int ret, n;

    printf("Change for : ");
    scanf("%d", &n);

    ret = min_coins(n);
    printf("Min # of coins : %d\n", ret);
    return 0;
}


