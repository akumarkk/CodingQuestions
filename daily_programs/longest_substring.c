#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
longest_substring(char *str, int k)
{
    int     start = 0, i; 
    int     max = -99;
    int     len = 0;
    int     uniq = 0;
    char    *sp = NULL;

    while(start < strlen(str) - k)
    {
        len = 1;
        uniq = 1;

        for(i=start+1; i < strlen(str) && uniq <= k; i++)
        {
            len++;
            if(str[i] == str[i-1])
                continue;

            if(uniq == k)
            {
                len--;
                break;
            }
            uniq++;
        }

        start++;
        if(len > max)
        {
            sp = str + (i - len);
            max = len;
        }
    }

    printf("Start of max sub string = %s\n", sp);
    return max;
}


int
main()
{
    char    str[1024];
    int     ret, i;

    printf("Str     :       ");
    scanf("%s", str);


    for(i=1; i<4; i++)
    {
        ret = longest_substring(str, 2);
        printf("k = %d  longest substring len = %d\n", i, ret);
    }

    return 0;
}

