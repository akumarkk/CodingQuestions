#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct stack__
{
    int top;
    int size;
    int *items;
}mystack_t;


mystack_t *stackset[100];
int curr = -1;

mystack_t *
get_stack();

    
void
init_stack(int size)
{
    stackset[++curr] = get_stack();
    stackset[curr]->top = -1;
    stackset[curr]->size = size;
    stackset[curr]->items = malloc(sizeof(int) *size);
    printf("Stack initialization successful\n");
}
    
    
    
mystack_t *
get_stack()
{
    mystack_t *s = malloc(sizeof(mystack_t));
    if(s == NULL)
	assert(0);
    return s;
}

void
print_stack()
{
    int i=0;
    for(i=0; i<=curr; i++)
    {
	printf("STACK(%d)   :	", i);
	for(int j=stackset[i]->top; j>=0; j--)
	    printf("[%d]   ", stackset[i]->items[j]);
	printf("END\n");
    }
}

int
push(int item)
{
    if(stackset[curr]->top + 1 == stackset[curr]->size)
    {
	if(curr +1 == 100)
	{
	    printf("MAX STACKS already allocated!!!\n");
	    return -1;
	}
	init_stack(5);
	//stackset[curr + 1] = get_stack();
	//curr++;
    }

    stackset[curr]->items[++stackset[curr]->top] = item;
    return 0;
}


int
pop()
{
    int item;

    if(stackset[curr]->top == -1)
    {
	printf("Stack(%d) is empty\n", curr);
	return -1;
    }

    item = stackset[curr]->items[stackset[curr]->top--];
    return item;
}

int
pop_at(int index)
{
    int item;
    if(stackset[index]->top == -1)
    {
	printf("Stack(%d) is empty\n", index);
	return -1;
    }
    
    item = stackset[index]->items[stackset[index]->top--];

    return item;
}

int 
main()
{
    init_stack(5);
    
    pop();

    push(5);
    push(15);
    push(25);
    push(35);
    print_stack();

    push(45);
    print_stack();

    push(101);
    push(102);
    push(103);
    push(104);
    push(105);
    print_stack();

    pop();
    print_stack();

    pop_at(0);
    print_stack();

    return 0;
}


