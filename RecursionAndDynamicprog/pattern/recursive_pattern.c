#include <stdio.h>
#include <string.h>

void
print_pattern(char *str, int index, char *buff, int buff_index)
{
    if(index == strlen(str))
    {
	buff[buff_index] = '\0';
	printf("%s\n", buff);
	return;
    }

    buff[buff_index] = str[index];
    print_pattern(str, index+1, buff, buff_index+1);

    buff[buff_index] = ' ';
    buff[buff_index+1] = str[index];
    print_pattern(str, index+1, buff, buff_index+2);
}

int
main()
{
    char str[1024], buff[2048];

    printf("STRING : ");
    scanf("%s", str);

    buff[0] = str[0];
    print_pattern(str, 1, buff, 1);
    return 0;
}
