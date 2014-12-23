#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct stack__
{
    int top;
    int size;
    int *items;
}mystack_t;

mystack_t *stack[2];

mystack_t *
init_stack(int size)
{
    mystack_t *s = malloc(sizeof(mystack_t));
    s->top = -1;
    s->size = size;
    s->items = malloc(sizeof(int) * size);
    return s;
}


void
get_stacks( )
{
    stack[0] = init_stack(5);
    stack[1] = init_stack(5);
}

/* Stack[0] - Insertions
 * stack[1] - deletions
 */

int
get_size()
{
    return (stack[0]->top + stack[1]->top + 2);
}


int
push(int id, int item)
{
    stack[id]->items[++stack[id]->top] = item;
    return item;
}



bool
is_empty(int id)
{
    if(stack[id]->top == -1)
	return true;
    return false;
}



int
pop(int id)
{
    int item=0;

    if(stack[id]->top < 0)
    {
	if(id == 1)
	{
	    while(! is_empty(0))
	    {
		item = pop(0);
		push(1, item);
	    }
	}
	else
	    return -1;
    }

    item = stack[id]->items[stack[id]->top];
    stack[id]->top--;

    return item;
}

    
    

#define MAX_SIZE 5

int
enqueue(int item)
{
    if(get_size() == MAX_SIZE)
    {
	printf("Reached max size!!!\n");
	return -1;
    }

    push(0,item);
    printf("Successful in enqueing  :	%d\n", item);
    return 0;
}

int
dequeue()
{
    int item = pop(1);
    return item;
}


void
print_stack()
{
    int i=0;
    for(i=1; i>=0; i--)
    {
	for(int j=stack[i]->top; j>=0; j--)
	{
	    printf("[%d]   ", stack[i]->items[j]);
	}
	printf("END\n");
    }
}


void
print_queue()
{
    print_stack();
}

int
main()
{
    get_stacks();

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);

    print_queue();
    dequeue();
    dequeue();
    dequeue();
    print_queue();

    dequeue();
    print_queue();
    dequeue();
    print_queue();
    dequeue();

    return 0;
}


