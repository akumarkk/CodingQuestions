#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DEBUG 0 
#define debug(fmt, ...)\
    do{\
	if(DEBUG)\
	    fprintf(stdout, "%s(%d) : " fmt "\n", __FUNCTION__, __LINE__, __VA_ARGS__);\
	fflush(stdout);\
    }while(0)

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

int key;

node_t *
get_closest_leaf(node_t *root, int *has_key_found, int *distance, int *key_dist)
{
    int	dist1 =0, dist2 = 0;
    int	left_has_key_found=0, right_has_key_found=0;
    node_t  *leaf = NULL, *right, *left;

    if(root == NULL)
    {
	*distance = 9999; // To indicate that there is no node
	return NULL;
    }

    if(root->left == NULL && root->right== NULL)
    {
	debug("LEAF NODE = %c	", root->data);
	if(root->data == key)
	{
	    *distance = 0;
	}
	else
	    *distance = 1;
	return root;
    }
    debug("processing node = %c ", root->data);

    if(*has_key_found == 1)
    {
	debug("Key is already found.", "");
	/* This is for the descendants of key */
	left = get_closest_leaf(root->left, has_key_found, &dist1, key_dist);
	right = get_closest_leaf(root->right, has_key_found, &dist2, key_dist);
	debug("DESCENDANTS CASE  left = %c  dist = %d	right = %c  dist = %d", left?left->data:9999, dist1, right?right->data:9999, dist2);

	if(dist1 < dist2)
	{

	    *distance = dist1 + 1;
	    debug("[%c] leaf = %c	distance = %d	", root->data, left->data, *distance);
	    return left;
	}
	else
	{
	    *distance = dist2 + 1;
	    debug("[%c] leaf = %c	distance = %d	", root->data, right->data, *distance);
	    return right;
	}
    }

    if(root->data == key)
    {
	*has_key_found = 1;
	debug("Key (%c) found here", key);
	left = get_closest_leaf(root->left, has_key_found, &dist1, key_dist);
	right = get_closest_leaf(root->right, has_key_found, &dist2, key_dist);
	*key_dist = 1;
	if(dist1 < dist2)
	{
	    *distance = dist1;
	    debug("[%c] leaf = %c    distance = %d   ",root->data, left->data, *distance);
	    return left;
	}
	else
	{
	    *distance = dist2 ;
	    debug("[%c] leaf = %c    distance = %d   ", root->data, right->data, *distance);
	    return right;
	}
    }

    left = get_closest_leaf(root->left, &left_has_key_found, &dist1, key_dist);
    right = get_closest_leaf(root->right, &right_has_key_found, &dist2, key_dist);

    if(left_has_key_found)
    {
	*has_key_found = 1;
	if(dist1 == 0)
	    return left;

	if((*key_dist + dist2) < dist1)
	{
	     *distance = dist2 + *key_dist;
	     *key_dist = *key_dist + 1;
	     debug("[%c] KEY FOUND leaf = %c    distance = %d   ", root->data, right->data, *distance);
	     return right;
	}
	else 
	{
	    *distance = dist1;
	    *key_dist = *key_dist + 1;
	     debug("[%c] KEY FOUND leaf = %c    distance = %d   ", root->data, left->data, *distance);
	    return left;
	}
    }
    else if(right_has_key_found)
    {
	*has_key_found = 1;
	if(dist2 == 0)
	    return right;

	if((*key_dist + dist1) < dist2)
	{
	    *distance = dist1 + *key_dist;
	    *key_dist = *key_dist + 1;
	     debug("[%c] KEY FOUND leaf = %c    distance = %d   ", root->data, left->data, *distance);
	    return left;
	}
	else
	{
	     *distance = dist2;
	     *key_dist = *key_dist + 1;
	      debug("[%c] KEY FOUND leaf = %c    distance = %d   ", root->data, right->data, *distance);
	     return right;
	}
    }
    else
    {
	debug("End case for node [%c]", root->data);
	if(dist1 < dist2)
	{
	    *distance = dist1;
	    return left;
	}
	else
	{
	    *distance = dist2;
	    return right;
	}
    }

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
    int	has_key_found = 0;
    node_t  *leaf;
    char    *str = "ABCEFGHIJK";


    key = 'E';
    printf("------------- key = %c-----------------------\n", key);
    leaf = get_closest_leaf(root, &has_key_found, &distance, &key_distance);
    printf("Key :   %c      Closest leaf    :   %c      Distace = %d\n", key, leaf->data, distance);

    for(i=0; i<9; i++)
    {
	key =  str[i];
	printf("------------- key = %c-----------------------\n", key);
	leaf = get_closest_leaf(root, &has_key_found, &distance, &key_distance); 
	printf("Key :	%c	Closest leaf	:   %c	    Distace = %d\n", str[i], leaf->data, distance);
	 distance =0; key_distance = 0; has_key_found = 0;
    
    }
    return 0;
}
