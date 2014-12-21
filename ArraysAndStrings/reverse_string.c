#include <stdio.h>
#include <string.h>

#define swap(a, b) {\
    a = a ^ b;\
    b = a ^ b;\
    a = a ^ b;\
}

int 
reverse_string(char *str)
{
    int i=0, j=0;
    int len = 0;

    if(str == NULL)
	return -1;

    len = strlen(str);
    
    if(len == 0  || len == 1)
	return 0;

    i=0; j=len-1;

    while(i < j)
    {
	if(str[i] != str[j])
	    swap(str[i], str[j]);
	i++;
	j--;
    }

    printf("REVERSED STRING : #%s#\n", str);
    return 0;
}


int
main()
{
    char str[1024] = "";
    printf("STRING : ");
    scanf("%s", str);

    reverse_string(str);
    return 0;
}

