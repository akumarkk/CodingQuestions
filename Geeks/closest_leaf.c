#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_
{
    int	    data;
    struct  node_ *left;
    struct  node_   *right;
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

int key_found;

node_t *
closest_leaf(node_t *root, int key, int *distance, int *key_dist)
{
    int	dist1, dist2;
    node_t  *leaf = NULL, *right, *left;

    if(root == NULL)
	return NULL;

    if(root->left == NULL && root->right== NULL)
    {
	if(root->data == key){
	    *key_dist = 1;
	    *distance = 0;
	}
	else
	    *distance = 1;
	return root;
    }

    if(root->data == key)
    {
	*key_dist = 1;
	key_found = 1;

	left = closest_leaf(root->left, key, &dist1, key_dist);
	right = closest_leaf(root->right, key, &dist2, key_dist);
	if(dist1 < dist2)
	{
	    leaf = left;
	    *distance = dist1;
	}
	else
	{
	    leaf = right;
	    *distance = dist2;
	}

	return leaf;
    }

    if(key_found)
    {
	left = closest_leaf(root->left, key, &dist1, key_dist);
	right = closest_leaf(root->right, key, &dist2, key_dist);
	if(dist1 < dist2)
	{
	    *distance = dist1 + 1;
	    return left;
	}
	else
	{
	    *distance = dist2 + 1;
	    return right;
	}
    }

    left = closest_leaf(root->left, key, &dist1, key_dist);
    if(key_found)
    {
	right = closest_leaf(root->right, key, &dist2, key_dist);
	if(dist2+ *key_dist < dist1)
	{
	    *distance = dist2 + *key_dist;
	    leaf = right;
	}
	else
	{
	    *distance = dist1;
	    leaf = left;
	}

	*key_dist += 1;
	return leaf;

    }

    right = closest_leaf(root->right, key, &dist2, key_dist);
    if(key_found)
    {
	if(dist1+*key_dist < dist2)
	{
	    *distance = dist1 + *key_dist;
	    leaf = left;
	}
	else
	{
	    *distance = dist2;
	    leaf = right;
	}
	*key_dist+=1;
	return leaf;
    }

    if(dist1 < dist2)
    {
	leaf = left;
	*distance = dist1 + 1;
    }else
    {
	 leaf = right;
	 *distance = dist2 + 1;
    }

    return leaf;
}

int
main()
{
    int i;
    node_t *root= get_node('A');
    root->left = get_node('B');
    root->right = get_node('C');
    root->right->left = get_node('E');
    root->right->left->left = get_node('G');
    root->right->left->left->left = get_node('I');
    root->right->left->left->right = get_node('J');
    root->right->right = get_node('F');
    root->right->right->right = get_node('H');
    root->right->right->right->left = get_node('K');

    int	key_distance =0, distance = 0;
    node_t  *leaf;
    char    *str = "ABCEFGHIJK";

#if 0
    distance =0; key_distance = 0; key_found = 0;
    leaf = closest_leaf(root, 'C', &distance, &key_distance); 
    printf("Key :	%c	Closest leaf	:   %c	    Distace = %d\n", 'C', leaf->data, distance);
    
    leaf = closest_leaf(root, 'F', &distance, &key_distance); 
    distance =0; key_distance = 0; key_found = 0;
    printf("Key :	%c	Closest leaf	:   %c	    Distace = %d\n", 'F', leaf->data, distance);
 
    distance =0; key_distance = 0; key_found = 0;
    leaf = closest_leaf(root, 'G', &distance, &key_distance); 
    printf("Key :	%c	Closest leaf	:   %c	    Distace = %d\n", 'G', leaf->data, distance);
#endif

    for(i=0; i<9; i++)
    {
	leaf = closest_leaf(root, str[i], &distance, &key_distance); 
	printf("Key :	%c	Closest leaf	:   %c	    Distace = %d\n", str[i], leaf->data, distance);
	 distance =0; key_distance = 0; key_found = 0;
    
    }
    return 0;
}
