#include <stdio.h>
#include <math.h>

int
main()
{
    int n;

    printf("Number : ");
    scanf("%d", &n);
    
    unsigned int k = log2(n&-n)+1;
    printf("Rightmost set bit of %d = %u\n", n, k);
    return 0;
}
