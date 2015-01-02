#include <stdio.h>
#include <string.h>

#define DEBUG 1
#define debug(fmt,...)\
    do{\
	if(DEBUG)\
	    fprintf(stdout, fmt "\n", __VA_ARGS__);\
    }while(0)

char str[100];

void
print_paranthesis(int open, int close, int n, int pos)
{
    debug("open = %d	close = %d  pos = %d	par = %s", open, close, pos, str);
    if(close == n)
    {
	printf("Para	:   %s\n", str);
	return;
    }

    if(open > close)
    {
	str[pos] = ')';
	print_paranthesis(open, close+1, n, pos+1);
    }
    if(open < n)
    {
	str[pos] = '(';
	print_paranthesis(open+1, close, n, pos+1);
	}
}

int
main()
{
    int n;
    printf("Enter the value of n    :	");
    scanf("%d", &n);

    print_paranthesis(0, 0, n, 0);
    return 0;
}
