#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
replace_space(char *str, char *replace_str)
{
    int i, newlen, len;
    int k=0, j=0, len1=0;
    int count = 0;

    if(str == NULL)
	return -1;

    len = strlen(str);
    if(len == 1 && str[0] != ' ')
	return 0;

    for(i=0; i<len; i++)
    {
	if(str[i] == ' ')
	    count++;
    }

    len1 = strlen(replace_str);
    newlen = (len + count * (len1-1)) - 1;
    str[newlen+1] = '\0';
    printf("Space count = %d	len=%d	newlen=%d\n", count, len, newlen);

    for(i=len-1; i>=0; i--)
    {
	if(str[i] == ' ')
	{
	    for(j=0,k=len1-1; j<len1; j++, k--)
	    {
		str[newlen-j] = replace_str[k];
	    }
	    newlen = newlen - len1;
	}
	else
	{
	    str[newlen] = str[i];
	    newlen--;
	}
    }
    
    return 0;
}

int 
main()
{
    char str[1024] = "University of Utah. This is a great school";
    char replace_str[100] = "";

    printf("REPLACE STRING : ");
    scanf("%s", replace_str);

    printf("GIVEN STRING : %s\n", str);
    replace_space(str, replace_str);
    printf("FINAL STRING : %s\n", str);

    return 0;
}



