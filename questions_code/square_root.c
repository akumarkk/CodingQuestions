#include <stdio.h>

#define MAX_DIFF 0.0000000001
double
square_root(double num)
{
    double n = num;
    double k = 1.0;
    
    while((k*k - n) > 0.0001 || (n - k * k) > 0.0001)
	k = (k + n /(2* k)) ;
	//k = (k + n / k) / 2;
    return k;
}

int
main()
{
    double num;
    double sqrt;

    printf("Number : ");
    scanf("%lf", &num);

    sqrt = square_root(num);
    printf("Square root is %lf \n", sqrt);
    return 0;
}
