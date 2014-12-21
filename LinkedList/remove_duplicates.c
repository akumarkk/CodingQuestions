#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node_
{
    int data;
    struct node_ *next;
}node_t;

node_t *
remove_duplicates(node_t *root)
{
    node_t *tmp, *curr, *unique=NULL;

    if(root == NULL || root->next == NULL)
	return root;

    curr = unique = root;
    root = root->next;
    curr->next = NULL;

    while(root != NULL)
    {
//	printf("processing %d\n", root->data);
	tmp = unique;
	while(tmp != NULL)
	{
	    if(tmp->data == root->data)
	    {
		root = root->next;
		break;
	    }
	    else
	    {
		tmp = tmp->next;
	    }
	}
	if(tmp == NULL)
	{
	    curr->next = root;
	    root = root->next;
	    curr = curr->next;
	    //printf("curr = %d added to list\n", curr->data);
	    curr->next = NULL;
	}
    }

    return unique;
}

node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}


void
print_list(char *str, node_t *root)
{
    printf("%s :\n", str);

    while(root != NULL)
    {
	printf("[%d]  ", root->data);
	root = root->next;
    }
    printf("[NULL]\n");
}



int
main()
{
    node_t *root = get_node(10);
    root->next = get_node(20);
    root->next->next = get_node(30);
    root->next->next->next = get_node(40);
    root->next->next->next->next = get_node(30);
    root->next->next->next->next->next = get_node(50);
    root->next->next->next->next->next->next= get_node(10);

    print_list("BEFORE", root);

    root = remove_duplicates(root);
    print_list("AFTER", root);

    return 0;
}

