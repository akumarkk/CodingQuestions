#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
is_right_rotation(char *str1, char *str2)
{
    int len1=strlen(str1), len2 = strlen(str2);
    int count=0, j, count1,i;

    for(i=0; i<len2; i++)
    {
	if(str1[count] == str2[i])
	    count++;
	else if(count)
	    return -1;
    }

    count1 = len2 - count;
    for(j=0,i=count;j<count1; j++)
	if(str1[i] == str2[j])
	    i++;
	else 
	    return -1;

    return 0;
}

int
main()
{
    char str1[100], str2[100];
    printf("str1 and str2   :");
    scanf("%s%s", str1, str2);

    int ret = is_right_rotation(str1, str2);
    if(ret == 0)
	printf("Right rotation\n");
    else
	printf("NOT RIGHT ROTATION\n");

    return 0;
}
