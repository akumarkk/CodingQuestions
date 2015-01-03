#include <stdio.h>
 
struct node {
	char *s;
	struct node* prev;
};
 
void powerset(char **v, int n, struct node *up)
{
	struct node me;
	printf("n = %d	Processing (%s)\n", n, *v);
 
	if (!n) {
	    printf("n=%d  ", n);
		putchar('[');
		while (up) {
			printf(" %s", up->s);
			up = up->prev;
		}
		puts(" ]");
	} else {
		me.s = *v;
		me.prev = up;
		powerset(v - 1, n - 1, up);
		powerset(v - 1, n - 1, &me);
	}
}
 
int main(int argc, char **argv)
{
	powerset(argv + argc -1, argc - 1, 0);
	return 0;
}
