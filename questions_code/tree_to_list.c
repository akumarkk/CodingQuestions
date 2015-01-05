#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_
{
    int data;
    struct node_ *left;
    struct node_ *right;
}node_t;

node_t *
inorder_tree_to_list(node_t *root)
{
    node_t *tmp = NULL;

    if(root == NULL)
	return NULL;

    if(root->left != NULL)
    {
	tmp = inorder_tree_to_list(root->left);
	/*inorder predecessor */
	while(tmp->right != NULL)
	    tmp = tmp->right;

	root->left = tmp;
	tmp->right = root;
    }
    if(root->right != NULL)
    {
	tmp = inorder_tree_to_list(root->right);
	
	/* Inorder successor */
	while(tmp->left != NULL)
	    tmp = tmp->left;

	root->right = tmp;
	tmp->left = root;
    }

    return root;
}


node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}


void
print_node(node_t *root)
{
    node_t *root1 = NULL;

    while(root != NULL)
    {
	printf("[%d]-->", root->data);
	root1 = root;
	root = root->right;
	
    }
    printf("[END]\n");


    while(root1 != NULL)
    {
	printf("[%d]<--", root1->data);
	root1 = root1->left;
    }
    printf("[END]\n");
}

int
main()
{
    node_t *root = get_node(10);
    root->left = get_node(12);
    root->right = get_node(15);
    root->left->left = get_node(25);
    root->left->right = get_node(30);
    root->right->left = get_node(36);

    root = inorder_tree_to_list(root);
    while(root->left != NULL)
	root = root->left;

    print_node(root);
    return 0;
}


