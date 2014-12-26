#include <stdio.h>
#include <stdlib.h>


typedef struct node_
{
    int data;
    struct node_ *left;
    struct node_ *right;
}node_t;

node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}


node_t *
mirror_btree(node_t *root)
{
    node_t *tmp;

    if(root == NULL)
	return root;

    if(root->left == NULL && root->right == NULL)
	return root;

    tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    mirror_btree(root->left);
    mirror_btree(root->right);

    return root;
}

node_t *
morris_traversal(node_t *root)
{
    node_t *tmp=NULL;

    if(root == NULL)
	return NULL;

    while(root != NULL)
    {
	if(root->left == NULL)
	{
	    printf("[%d] ", root->data);
	    root = root->right;
	}
	else
	{
	    tmp = root->left;
	    while(tmp->right != NULL && tmp->right != root)
		tmp = tmp->right;

	    if(tmp->right == NULL)
	    {
		tmp->right = root;
		root = root->left;
	    }
	    else
	    {
		printf("[%d]  ", root->data);
		tmp->right = NULL;
		root = root->right;
	    }
	}
    }

    printf("NULL\n");
    return root;
}

int
main()
{
    node_t *root = get_node(4);
    root->left = get_node(2);
    root->left->left = get_node(1);
    root->left->right = get_node(3);
    root->right = get_node(5);

    morris_traversal(root);
    root = mirror_btree(root);
    morris_traversal(root);

    return 0;
}

