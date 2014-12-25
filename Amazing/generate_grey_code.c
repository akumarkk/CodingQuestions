#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **
generate_greycode(int n)
{
    int max = 1<<n;

    char **greycode;
    int i, j, k, p;

    greycode = malloc(sizeof(char *) * max);

    for(i=0; i<max; i++)
    {
	greycode[i] = malloc( n+1);
	memset(greycode[i], '\0', n+1);
    }

    greycode[0][n-1] = '0';
    greycode[1][n-1] = '1';

    //printf("greycode[0] = %s	greycode[1] = %s\n\n", greycode[0], greycode[1]);
    for(i=1; i<n; i++)
    {
	k = 1<<i;

	for(j=k, p=k-1; j<(2*k); j++,p--)
	{
	    greycode[p][n-i-1] = '0';
	    //printf("i=%d j=%d p=%d greycode[%d] = %s\n", i, j, p, p, (greycode[p]+(n-i)));
	    memcpy(greycode[j], greycode[p], n);
	    greycode[j][n-i-1] = '1';
	    //printf("Bit = %d	greycode[%d] = %s   greycode[%d] = %s\n", i, p, greycode[p]+n-i,j, greycode[j]+n-i);
	    //printf("\n");
	}
	//printf("\n");
    }

    return greycode;
}

int
main()
{
    int n, max, i;
    printf("Bits in greycode : ");
    scanf("%d", &n);

    max = 1<<n;
    char **greycode = generate_greycode(n);

    for(i=0; i<max; i++)
	printf("%s\n", (char *)greycode[i]);

    return 0;
}
