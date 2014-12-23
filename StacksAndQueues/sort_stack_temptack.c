#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


typedef struct stack__
{
    int top;
    int size;
    int *items;
}mystack_t;

mystack_t  stack[2];

void
init_stack(int size)
{
    stack[0].top = -1;
    stack[0].size = size;
    stack[0].items = malloc(sizeof(int) * size);

    stack[1].top = -1;
    stack[1].size = size;
    stack[1].items = malloc(sizeof(int) * size);
}

void
print_stack()
{
    int i, j;

    for(i=0; i<2; i++)
    {
	printf("STACK(%d)   :	", i);
	for(j=stack[i].top; j>=0; j--)
	    printf("[%d]   ", stack[i].items[j]);
	printf("END\n");
    }
}

bool
is_stack_empty(int id)
{
    if(stack[id].top == -1)
	return true;
    return false;
}


int 
pop_at(int id)
{
    int item;

    if(stack[id].top == -1)
	return -1;

    item = stack[id].items[stack[id].top];
    stack[id].top--;
    return item;
}

int
push(int id, int item)
{
    if(stack[id].top+1 == stack[id].size)
	return -1;

     stack[id].items[++stack[id].top] = item;
     return item;
}


int
sort_stack( )
{
    int item1, item2;

    while(!is_stack_empty(0))
    {
	item1 = pop_at(0);
	item2 = pop_at(1);
	
	printf("Processing item1 = %d	item2 = %d\n", item1, item2);

	if(item2 <= item1)
	{
	    if( !is_stack_empty(1) || item2 != -1)
	    {
		/* For the first item, item2 will be -1
		 */
		printf("Stack is not empty\n");
		push(1, item2);
		push(1, item1);
	    }
	    else
	    {
		printf("Stack is EMPTY. So pushing only (%d)\n", item1);
		push(1, item1);
	    }
	}
	else
	{
	    /* This is based on the idea that pop() returns -1 on empty.
	     * In this case, item2 < item1 and hence loop should terminate.
	     */
	    while(item2 > item1)
	    {
		push(0,item2);
		item2 = pop_at(1);
	    }
	    if( !is_stack_empty(1) || item2 != -1)
	    {
		push(1, item2);
		push(1, item1);
	    }
	    else
	    {
		/* We popped all the items from stack2.
		 */
		push(1, item1);
	    }
	}
	print_stack();
	printf("------ END PASS --------\n\n");

    }

    return 0;
}


int
main()
{
    init_stack(10);

    push(0, 1);
    push(0, 7);
    push(0, 2);
    push(0, 4);
    push(0, 3);
    push(0, 13);
    push(0, 20);
    push(0, 0);
    push(0, 66);
    push(0, 9);
    push(0, 55);

    print_stack();

    sort_stack();
    print_stack();
    return 0;
}
