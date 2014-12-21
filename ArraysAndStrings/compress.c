#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 1024

char *
compress(char *str)
{
    int i=0, len=0;
    int k=1,count;

    len = strlen(str);
    static char str1[MAX_SIZE];

    if(str == NULL)
	return NULL;

    if(len == 1)
	return str;


    count = 1;
    str1[0] = str[0];

    for(i=1; i<=len; i++)
    {
	if(str[i-1] == str[i])
	{
	    count++;
	}
	else
	{
	    snprintf(str1+k, MAX_SIZE, "%d", count);
	    k = strlen(str1);
	    str1[k++] = str[i];
	    count = 1;
	}
    }


    if(k < len)
	return str1;
    else 
	return str;
}

int
main()
{
    char str[1024] = "";
    printf("STRING : ");
    scanf("%s", str);

    printf("STRING = %s\nCOMPRESSED STRING = %s\n", str, compress(str));
    return 0;
}
