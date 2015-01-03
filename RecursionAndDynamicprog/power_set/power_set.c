#include <stdio.h>
#include <string.h>

void
power_set(char *set)
{
    int len = strlen(set);
    int counter, i;

    int power = pow(2, len);
    for(counter=0; counter<power; counter++)
    {
	for(i=0; i<len; i++)
	{
	    if(counter & (1<<i))
		printf("[%c], ", set[i]);
	}
	printf("[END]\n");
    }

}

int
main()
{
    char *set = "abcd";
    power_set(set);
    return 0;
}
