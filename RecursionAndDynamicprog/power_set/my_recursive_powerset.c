#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	char s[3];
	struct node* prev;
};
 
char str[1024] ;

    
struct node *
get_node()
{
    struct node *tmp = malloc(sizeof(struct node ));
    tmp->prev = NULL;
    return tmp;
}

void powerset(int index,  struct node *up)
{
	struct node *me = get_node();
	//printf("n = %d	Processing (%c)\n", index, str[index]);
 
	if (index < 0) {
	    printf("n=%d  ", index);
		putchar('[');
		while (up) {
			printf(" %s", up->s);
			up = up->prev;
		}
		puts(" ]");
	} else {
	    
		me->s[0] = str[index];
		me->s[1] = '\0';
		me->prev = up;
		powerset(index - 1,  up);
		powerset(index - 1,  me);
	}
}
 
int main(int argc, char **argv)
{
    printf("STRING : ");
    scanf("%s", str);

	powerset(strlen(str)-1, 0);
	return 0;
}
