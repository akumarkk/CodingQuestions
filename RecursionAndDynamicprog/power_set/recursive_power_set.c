#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_
{
    char ch;
    struct node_ *next;
}node_t;

node_t *
get_node(char ch)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->ch = ch;
    tmp->next = NULL;
    return tmp;
}

char str[1024];
/* Idea here is :
 *	to print subsets of n characters, 
 *	    - append nth character to (n-1) subsets and print
 *	    - Print (n-1) subsets
 *	So in each iteration, create a node, invoke 
 *	- power_set with (n-1) items and 
 *	- power_set with n and n-1 items
 */
void
recursive_power_set(int index, node_t *curr)
{
    if(index < 0)
    {
	printf("[ ");
	while(curr != NULL)
	{
	    printf("%c ", curr->ch);
	    curr = curr->next;
	}
	printf("]\n");
	
	return;
    }

    node_t *node = get_node(str[index]);
    node->next = curr;
    recursive_power_set(index-1, curr);
    recursive_power_set(index-1, node);
}

int
main()
{
    printf("STRING  : ");
    scanf("%s", str);

    recursive_power_set(strlen(str)-1, NULL);
    return 0;
}

