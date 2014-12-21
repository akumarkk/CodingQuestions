#include <stdio.h>
#include <stdlib.h>

/* This will work only if mid next node is not null.
 *
 * Also here we should only copy the value of mid->next to mid, but not the actual pointers.
 * because copying pointers will break the link with previous node.
 */
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
print_list(node_t *node)
{
    while(node != NULL)
    {
	printf("[%d]-->", node->data);
	node = node->next;
    }
    printf("[NULL]\n");
}

int
delete_mid(node_t *mid)
{
    if(mid == NULL || mid->next == NULL)
	return -1;

    mid->data = mid->next->data;
    mid->next = mid->next->next;
    return 0;
}

int 
main()
{
    node_t *root = get_node(10);
    root->next = get_node(20);
    root->next->next = get_node(30);
    root->next->next->next = get_node(40);
    root->next->next->next->next = get_node(40);

    print_list(root);
    delete_mid(root->next->next);
    print_list(root);

    return 0;
}

