#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
    int data;
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
print_list(node_t *root)
{
    while(root != NULL)
    {
	printf("[%d]-->", root->data);
	root = root->next;
    }
    printf("[NULL]\n");
}



node_t *
partition_aroud_value(node_t *root, int value)
{
    node_t *tmp, *front, *rear;

    if(root == NULL || root->next == NULL)
	return root;

    front = rear = root;
    root = root->next;
    while(root != NULL)
    {
	if(root->data < value)
	{
	    tmp = root;
	    root = root->next;
	    tmp->next = front;
	    front = tmp;
	}
	else
	{
	    rear->next = root;
	    root = root->next;
	    rear = rear->next;
	}
    }
    rear->next = NULL;

    return front;
}


int
main()
{
    node_t *root = get_node(10);
    root->next = get_node(20);
    root->next->next = get_node(5);

    print_list(root);
    root = partition_aroud_value(root, 10);
    print_list(root);

    root->next->next->next = get_node(25);
    root->next->next->next->next = get_node(55);
    root->next->next->next->next->next = get_node(15);
    root->next->next->next->next->next->next = get_node(2);

    print_list(root);
    root = partition_aroud_value(root, 20);
    print_list(root);

    return 0;
}

    

