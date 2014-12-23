#include <stdio.h>
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
    while(!is_stack_empty(1))
    {
	item1 = pop_at(1);
	item2 = pop_at(2);
	if(item2 <= item1)
	{
	    push(2, item2);
	    push(2, item1);
	}
	else
	{
	    /* This is based on the idea that pop() returns -1 on empty.
	     * In this case, item2 < item1 and hence loop should terminate.
	     */
	    while(item2 > item1)
	    {
		push(1,item2);
		item2 = pop(2);
	    }
	    if( !is_stack_empty(2))
	    {
		push(2, item2);
		push(2, item1);
	    }
	    else
	    {
		/* We popped all the items from stack2.
		 */
		push(2, item1);
	    }
	}

    }

    return 0;
}



