#include <stdio.h>
#include <stdlib.h>

typedef struct stack__
{
    int top;
    int size;
    int *items;
}mystack_t;

mystack_t stack, aux_stack;

void
init_stack(int size)
{
    stack.size = size;
    stack.top = -1;
    stack.items = malloc(sizeof(int) *size);

    aux_stack.size = size;
    aux_stack.top = -1;
    aux_stack.items = malloc(sizeof(int) *size);
}

int
push(int item)
{
    static int minvalue = 999999;


    if(stack.top+1 == stack.size)
    {
	printf("STACK is full !!!\n");
	return -1;
    }

    if(minvalue > item)
	minvalue = item;

    stack.items[++stack.top] = item;
    aux_stack.items[++aux_stack.top] = minvalue;
    
    return 0;
}

int
get_min()
{
    if(stack.top == -1)
    {
        printf("STACK is empty!!!\n");
        return -1;
    }
    
    return aux_stack.items[aux_stack.top];
}



void
print_stack()
{
    int i=0;


    for(i=stack.top; i>=0; i--)
	printf("[%d]   ", stack.items[i]);
    printf("END\n");
}

int
pop()
{
    int item;

    if(stack.top == -1)
    {
	printf("STACK is empty!!!\n");
	return -1;
    }

    item = stack.items[stack.top--];
    aux_stack.top--;
    printf("Popped an item  :	%d\n", item);

    return item;
}


int
main()
{
    init_stack(10);

    push(10);
    push(11);
    push(12);
    push(13);

    print_stack();
    printf("Min = %d\n", get_min());

    push(5);
    printf("Min = %d\n", get_min());
    print_stack();
    
    pop();
    printf("Min = %d\n", get_min());

    pop();
    printf("Min = %d\n", get_min());

    pop();
    printf("Min = %d\n", get_min());
    
    pop();
    printf("Min = %d\n", get_min());

    pop();
    printf("Min = %d\n", get_min());

    return 0;
}


