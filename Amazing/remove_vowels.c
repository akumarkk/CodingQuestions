#include <stdio.h>
#include <string.h>

char *
remove_vowels(char *str)
{
    int len = strlen(str), i;
    int k = 1;

    for(i=1; i<len; i++)
    {
	if(str[i]== 'a' || str[i]== 'e' || str[i]== 'i'|| str[i]== 'o'|| str[i]== 'u'||
		str[i]== 'A'|| str[i]== 'E'|| str[i]== 'I'|| str[i]== 'O'|| str[i]== 'U')
	    continue;
	else
	    str[k++] = str[i];
    }
    str[k] = '\0';
    return str;
}

int
main()
{
    char str[200];

    printf("String : ");
    scanf("%s", str);

    remove_vowels(str);
    printf("Modified string : %s\n", str);

    return 0;
}
