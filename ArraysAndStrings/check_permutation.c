/* This can also be implemented by :
 * 1. Sorting both the strings
 * 2. Compare each char of the strings
 */


#include <stdio.h>
#include <string.h>
#include <stdint.h>

int
is_permutation(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i=0;    
    int8_t letters1[128] = {0};

    if(len1 != len2)
	return -1;

    for(i=0; i<len1; i++)
    {
	letters1[str1[i]]++;
    }

    for(i=0; i<len2; i++)
    {
	printf("letters1[%c] = %d\n", str2[i], letters1[str2[i]]);
	if((--letters1[str2[i]]) < 0)
	    return -1;
    }
    return 0;
}

int
main()
{
    char str[1024], str2[1024];

    printf("Strings <str1> <str2> :");
    scanf("%s%s", str, str2);

    printf("PERMUTATION :   %d\n", is_permutation(str, str2));
    return 0;
}


