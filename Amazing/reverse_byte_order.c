#include <stdio.h>

#define swap(a, b) do{\
    if(a != b) {\
	a = a ^ b;\
	b = a ^ b;\
	a = a ^ b;\
    }\
}while(0)

int
main()
{
    int x = 0x45567890;
    char *ch;
    int i, j;
    ch = (char *)&x;

    int len = sizeof(int);

    printf("Given number = %x\n", x);

    for(i=0; i<len; i++)
	printf("%d byte	    :	%02x\n", i, (char)ch[i]);

    i = 0; j = len-1;
    while(i < j)
    {
	swap(ch[i], ch[j]);
	i++;
	j--;
    }

    for(i=0; i<len; i++)
	printf("%d byte     :   %x\n", i, ch[i]);

    printf("Given number = %x\n", x);
    return 0;
}
