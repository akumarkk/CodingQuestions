#include <stdio.h>
#include <stdlib.h>


typedef struct node_
{
    int	    data;
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
minimal_bst(int *a, int low, int high)
{
    int mid;
    if(low > high)
	return NULL;
    
    mid = (low + high)/2;
    node_t *tmp = get_node(a[mid]);
    tmp->left = minimal_bst(a, low, mid-1);
    tmp->right = minimal_bst(a, mid+1, high);
    return tmp;
}

void
print_bst(node_t *root)
{
    node_t *tmp = root;
    if(root == NULL)
	return;

    while(root != NULL)
    {
	if(root->left == NULL)
	{
	    printf("[%d]   ", root->data);
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
    printf("[NULL]\n");
}




int
main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    node_t *root = minimal_bst(a, 0, 6);
    
    print_bst(root);
    root = minimal_bst(a, 0, 5);
    print_bst(root);

    return 0;
}
    

