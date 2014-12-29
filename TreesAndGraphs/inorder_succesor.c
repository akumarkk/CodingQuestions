#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
    int	    data;
    struct node_ *parent;
    struct node_ *left;
    struct node_ *right;
}node_t ;

node_t *
get_node(int data)
{
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = data;
    tmp->parent = NULL;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void
print_bt(node_t *root)
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



node_t *
inorder_succesor(node_t *root)
{
    node_t *par, *tmp;

    if(root == NULL)
	return NULL;


    if(root->right)
    {
	tmp = root->right;
	while(tmp->left != NULL)
	    tmp = tmp->left;
	return tmp;
    }
    else
    {
	if(root->parent == NULL)
	    return NULL;
	
	if(root->parent->right == root)
	{
	    tmp = root;
	    par = tmp->parent;
	    while(tmp != NULL && par && tmp != par->left)
	    {
		tmp = par;
		par = par->parent;
	    }
	    return par;
	}
	else
	    return root->parent;
    }

}

int
main()
{
    node_t  *tmp;
    node_t *root = get_node(1);
    root->right = get_node(2);
    root->right->parent = root;

    root->left = get_node(20);
    root->left->parent = root;

    root->right->right = get_node(3);
    root->right->right->parent = root->right;

    root->right->right->right = get_node(6);
    root->right->right->right->parent = root->right->right;

    root->right->right->right->left = get_node(8);
    root->right->right->right->left->parent = root->right->right->right;
    tmp = inorder_succesor(root->right->right->right);
    
    printf("INORDER SUCCESSOR(6) :	%d\n", tmp?tmp->data:9999);
    
    tmp = inorder_succesor(root->right->right->right->left);
    printf("INORDER SUCCESSOR(8) :	%d\n", tmp?tmp->data:9999);

    tmp = inorder_succesor(root->right);
    printf("INORDER SUCCESSOR(2) :      %d\n", tmp?tmp->data:9999);

    tmp = inorder_succesor(root);
        printf("INORDER SUCCESSOR(1) :      %d\n", tmp?tmp->data:9999);
    
    tmp = inorder_succesor(root->left);
    printf("INORDER SUCCESSOR(20) :      %d\n", tmp?tmp->data:9999);    
    print_bt(root);    
    return 0;
}
