#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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



node_t *
add_list(node_t *list1, node_t *list2, int *carry)
{
    node_t *sum;
    int s = 0;

    if(list1 == NULL || list2 == NULL)
	return NULL;

    sum = get_node(s);
    
    if(sum == NULL)
	assert(0);


    if(list1->next == NULL && list2->next == NULL)
    {
	s = list1->data + list2->data;
	*carry = s /10;
	s = s % 10;
	sum->data = s;
	//printf("DATA Sum=%d carry=%d\n", s, *carry);
	return sum;
    }

    sum->next = add_list(list1->next, list2->next, carry);
    s = list1->data + list2->data + *carry;
    *carry = s /10;
    s = s % 10;
    sum->data = s;
    //printf("DATA_END Sum=%d carry=%d\n", s, *carry);

    return sum;
}


int
count_list(node_t *root)
{
    int count = 0;

    if(root == NULL)
	return 0;

    while(root != NULL)
    {
	root = root->next;
	count++;
    }

    return count;
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
add_carry(node_t *list, node_t *sum, int *carry, int count, int i)
{
    node_t *sum_node;

    if(list == NULL)
	return NULL;

    if(i == count-1)
    {
	sum_node = get_node((*carry + list->data) % 10);
	*carry = (*carry + list->data) / 10;
	sum_node->next = sum;
	//printf("sum_node sum = %d   carry = %d\n", sum_node->data, *carry);
	return sum_node;
    }

    sum_node = get_node(0);
    sum_node->next = add_carry(list->next, sum, carry, count, i+1);
    sum_node->data = (*carry + list->data) % 10;
    *carry = (*carry + list->data) / 10;
 
    return sum_node;

}


node_t *
add_two_lists(node_t *list1, node_t *list2)
{
    node_t *sum, *sum_node;
    int i=1;
    node_t *tmp=NULL;
    int diff, count1, count2, carry=0;


    if(list1 == NULL || list2==NULL)
	return NULL;

    count1 = count_list(list1);
    count2 = count_list(list2);

    //printf("count1 = %d	    count = %d\n", count1, count2);

    if(count1 != count2)
    {
	if(count1 > count2)
	{
	    diff = count1 - count2;
	}
	else
	{
	    tmp = list1;
	    list1 = list2;
	    list2 = tmp;
	    diff = count2 - count1;
	}

	tmp = list1;
	while(i <= diff)
	{
	    tmp = tmp->next;
	    i++;
	}

	//printf("diff = %d   i = %d	data = %d\n", diff, i, tmp->data);
	//printf("list1 = [%d]	list2 = [%d]\n", tmp->data, list2->data);

	sum = add_list(tmp, list2, &carry);
	//printf("SUM LIST : ");
	//print_list(sum);

	//printf("\nsum = [%d]	list1 = [%d]  carry = %d\n", sum->data, list1->data, carry);
	sum = add_carry(list1, sum, &carry, diff, 0);
	if(carry == 0)
	    return sum;

	sum_node = get_node(carry);
	sum_node->next = sum;
	return sum_node;
    }
    else
    {
	sum = add_list(list1, list2, &carry);
	if(carry == 0)
	    return sum;

	sum_node = get_node(carry);
	sum_node->next = sum;
	return sum_node;
    }

    return sum;
    //Normally control will never reaches here.
}

int
main()
{
    node_t *sum = NULL;

    node_t *root = get_node(1);
    root->next = get_node(2);
    root->next->next = get_node(3);
    root->next->next->next = get_node(9);

    node_t *root1 = get_node(9);
    root1->next = get_node(9);
    root1->next->next = get_node(9);
    root1->next->next->next = get_node(9);
    root1->next->next->next->next = get_node(5);
    root1->next->next->next->next->next = get_node(9);

    print_list(root);
    print_list(root1);
    sum = add_two_lists(root, root1);
    print_list(sum);

    return 0;
}
