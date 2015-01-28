#include <stdio.h>

int den[] = {1, 5, 10, 20, 25};

int
min_den(int n)
{
    int min = 9999;
    int ret = 0;

    if(n<=0)
	return -1;
    if(n == 0)
	return 0;

    for(int i=0; i<5; i++)
    {
	if(n == den[i])
	    return 1;
    }

    for(int i=0; i<5; i++)
    {
	ret = min_den(n-den[i]) + 1;
	//printf("n = %d	    ret = %d\n", n, ret);

	if((ret != -1) && ret  &&ret < min)
	    min = ret;
	 //printf("n = %d      min = %d\n", n, min);
    }
    return min;
}

int
main()
{
    printf("min_den = %d\n", min_den(5));
    printf("min_den for (%d) = %d\n",7,  min_den(7));
    printf("min_den for (%d) = %d\n", 40, min_den(40));
    printf("min_den for (%d) =  %d\n",50,  min_den(50));

    return 0;
}

