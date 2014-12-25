#include <string.h>
#include <stdio.h>

int
main()
{
    char str1[100] = "";
    char str2[100] = "";

    str1[10] = 'A';
    str2[5] = 'B';

    printf("str1 = %s %c	str2 = %s %c\n", str1,str1[10],  str2, str2[5]);

    strcpy(str1, str2);
    printf("str1 = %s %c	str2 = %s %c\n", str1,str1[10],  str2, str2[5]);
    
    return 0;
}
