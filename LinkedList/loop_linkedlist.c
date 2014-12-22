#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


node_t *
detect_loop(node_t *root)
{
    node_t *prev=NULL, *prev1 = NULL;
    node_t *fast=root, *slow=root;

    if(root == NULL || root->next == NULL)
	return NULL;

    while(slow && fast && (fast->next!= NULL) )
    {
	prev = slow;
	slow = slow->next;

	prev1 = fast;
	fast = fast->next->next;
	
	if(slow == fast)
	{
	    printf("prev = [%d]	    prev1 = [%d]\n", prev->data, prev1->data);
	    return slow;
	}
    }

    if(fast == NULL || slow == NULL)
	return NULL;
    
    return NULL;
}

int
main()
{
    node_t *tmp = NULL;
    node_t *root = get_node(10);
    root->next = get_node(20);
    root->next->next = get_node(30);
    root->next->next->next = get_node(40);
    root->next->next->next->next = get_node(50);
    root->next->next->next->next->next = get_node(60);
    root->next->next->next->next->next->next = root->next->next;

    //print_list(root);
    tmp = detect_loop(root);

    if(tmp)
	printf("Loop detectd at [%d]\n", tmp->data);
    else
	printf("NO LOOP DETECTED\n");

    return 0;
}
