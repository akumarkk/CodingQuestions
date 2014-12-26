#include <stdio.h>
#include <stdlib.h>


int **
get_intersection(int **a, int num_sets, int *size)
{
    int i=0, j=0;
    int m, k, count, minset, minsize;
    int **tmp;

    for(i=0; i<numsets; i++)
    {
	if(minsize > size[i])
	{
	    minset = i;
	    minsize = size[i];
	}

	sort_set(a[i], size[i]);
    }


    tmp = malloc(2 * sizeof(int *));
    tmp[0] = malloc(sizeof(int) * minsize);
    tmp[1] = malloc(sizeof(int) * minsize);

    count = 1;
    k = 0;
    tmp[0][k] = a[minset][0];

    for(i=1; i<size[minset]; i++)
    {
	if(a[minset][i] == a[minset][i-1])
	    count++;
	else
	{
	    tmp[1][k] = count;
	    tmp[0][++k] = a[minset][i];
	    count = 1;
	}
    }
    tmp[1][k] = count;


     m=0;
     for(i=0; i<k; i++)
     {
	 for(j=0; j<num_sets; j++)
	 {
	     if( i != j )
	     {

		count = get_frequency(a[j], size[j], tmp[0][i]);
		if(count == 0)
		    break;
		else 
		{
		    tmp[0][m] = tmp[0][i];
		    tmp[1][m] = (count < tmp[1][i])?count: mp[1][i];
		    m++;
		}
	     }
	}
     }

     return 0;
}

