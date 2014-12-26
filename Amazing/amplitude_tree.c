/* 
 * In a binary tree T, a path P is a non-empty sequence of nodes of tree such that, each consecutive node in the sequence is a subtree of its preceding node. In the example tree, the sequences [9, 8, 2] and [5, 8, 12] are two paths, while [12, 8, 2] is not. The amplitude of path P is the maximum difference among values of nodes on path P. The amplitude of tree T is the maximum amplitude of all paths in T. When the tree is empty, it contains no path, and its amplitude is treated as 0.
 */
// http://codesays.com/2014/solution-to-tree-amplitude/

#include <stdio.h>
#include <stdlib.h>


typedef struct node_
{
    int data;
    struct node_ *left;
    struct node_ *right;
}node_t;


int
get_max_amplitude(node_t *tree, int max, int min)
{
    int leftmax, rightmax;

    if(tree == NULL)
	return 0;

    if(tree->data > max)
	max = tree->data;
    if(tree->data < min)
	min = tree->data;


    if(tree->left == NULL && tree->right == NULL)
	return max-min;

    leftmax = get_max_amplitude(tree->left, max, min);
    rightmax = get_max_amplitude(tree->right, max, min);

    if(rightmax > leftmax)
	return rightmax;
    else
	return leftmax;

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

int
main()
{
    int ret=0;
    node_t *root = get_node(5);
    root->left = get_node(8);
    root->right = get_node(9);
    root->right->left = get_node(8);
    root->right->left->left = get_node(2);
    root->right->right = get_node(4);
    root->right->right->left = get_node(5);
    root->left->right = get_node(2);
    root->left->left = get_node(12);
    root->left->left->right = get_node(50);
    root->left->left->left = get_node(51);

    ret = get_max_amplitude(root, root->data, root->data);
    printf("Maximum aplitude of the tree : %d\n", ret);

    return 0;
}
