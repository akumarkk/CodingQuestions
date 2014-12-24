#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/* To check whether given codes are consecutive grey code or not, 
 *  1. Flip the rightmost bit of a given grey code
 *  2. Flip the bit left to rightmost bit of a given grey code.
 *
 *  If the second code is equal to any of the above numbers, then true.
 */
bool
check_grey_codes(int a, int b)
{
    int a1 = a ^ 1;
    int a2 = a ^ ((a&-a)<<1);
    
    printf("Grey codes of %X : %x %x\n", a, a1, a2);

    if(b == a1 || b == a2)
	return true;
    return false;
}

int
main()
{
    int a, b;
    printf("Grey codes :    ");
    scanf("%d%d", &a, &b);

    if(check_grey_codes(a, b))
	printf("%x and %x are consecutive Grey codes\n", a, b);
    else
	printf("%x and %x are NOT consecutive grey codes\n", a, b);

    return 0;
}
