#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define DEBUG 1 
#define debug(fmt, ...)\
    do{\
	if(DEBUG)\
	    fprintf(stdout, "%s(%d): "fmt "\n", __FUNCTION__, __LINE__, __VA_ARGS__);\
    }while(0)

bool
is_digit(char ch)
{
    if(ch >= '0' && ch<= '9')
	return true;
    return false;
}


int
my_atoi(char *str)
{
    int i=0;
    int num = 0, len;

    if(str == NULL)
	return -1;

    len = strlen(str);
    if(len == 0)
	return -1;

    for(i=0; i<len; i++)
    {
	if(is_digit(str[i]))
	    num = num*10 + (str[i] - '0');
	else
	    break;
	debug("i=%d num = %d", i, num);
    }

    return num;
}

int
main()
{
    char str[100];
    int  num=0;
    printf("String : ");
    scanf("%s", str);

    num = my_atoi(str);
    debug("numerical value of %s = %d\n", str, num);
    return 0;
}
