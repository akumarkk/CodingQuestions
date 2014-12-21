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
get_kthnode(node_t *root, int k)
{
    int count=1;
    node_t *tmp=NULL;

    if(root == NULL || root->next == NULL)
	return root;

    tmp = root;
    while(tmp->next != NULL && (count < k))
    {
	tmp = tmp->next;
	count++;
    }
    if(count < k)
    {
	printf("Invalid value\n");
	return NULL;
    }

    while(tmp->next != NULL)
    {
	root = root->next;
	tmp = tmp->next;
    }
    return root;
}


int
main()
{
    node_t *tmp= NULL;
    node_t *root = get_node(10);
    root->next = get_node(20);

    print_list(root);
    printf("1st node	:   [%d]\n", (tmp=get_kthnode(root, 1))?tmp->data:9999);
    printf("2nd node	:   [%d]\n", (tmp=get_kthnode(root, 2))?tmp->data:9999);

    root->next->next = get_node(30);
    root->next->next->next = get_node(40);
    root->next->next->next->next = get_node(50);
    root->next->next->next->next->next = get_node(60);
    print_list(root);
    printf("3rd node	:   [%d]\n", (tmp=get_kthnode(root, 3))?tmp->data:9999);
    printf("7th node	:   [%d]\n", (tmp=get_kthnode(root, 7))?tmp->data:9999);
    return 0;
}
