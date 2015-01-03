/* If there are n characters in a given string, 2^n-1 combinations are possible.
 * In each combination, space should also be included in the positions where bit is set.
 * For example : ABC
 * 4 combinations are possible. 
 *  -	00 insert no space
 *  -	01 insert space in the second position
 *  -	10 insert space in the third position
 *  -	11 insert space in the second and third position
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void
print_pattern(char *str)
{
    int len;
    int count, k, j, i;
    char *buff;

    len = strlen(str);
    count = pow(2, len-1);

    buff = malloc(2*len);

    for(i=0; i<count; i++)
    {
	k = -1;
	for(j=0; j<len; j++)
	{
	    if(i & (1<<j))
	    {
		buff[++k] = str[j];
		buff[++k] = ' ';
	    }
	    else
	    {
		buff[++k] = str[j];
	    }
	}
	buff[++k] = '\0';
	printf("(%d)	%s\n", i, buff);
    }
}

int
main()
{
    char str[1024] = "";

    printf("STRING : ");
    scanf("%s", str);

    print_pattern(str);
    return 0;
}
