#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_
{
    int	    data;
    struct node_ *next;
}node_t;


node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}


void
print_subset(int *a, int index, node_t *curr)
{
    if(index < 0)
    {
	printf("[");
	while(curr != NULL)
	{
	    printf("%d ", curr->data);
	    curr = curr->next;
	}
	printf("]\n");

	return;
    }

    node_t *tmp = get_node(a[index]);
    tmp->next = curr;
    print_subset(a, index-1, tmp);
    print_subset(a, index-1, curr);
}

int
main()
{
    int a[100], n;

    printf("# of items : ");
    scanf("%d", &n);

    printf("Key-in items : ");
    for(int i=0; i<n; i++)
	scanf("%d", &a[i]);

    print_subset(a, n-1, NULL);
    return 0;
}
