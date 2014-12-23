#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct stack_
{
    int	    top;
    int	    *end;
    int	    start;
}stack_attr_t;

stack_attr_t stack_attr[3];

static int stack_data[10];

void
print_stack(int id)
{
    int i=0;
    if(id == 1)
    {
	for(i=stack_attr[id].top; i<=stack_attr[id].start; i++)
	    printf("[%d]   ", stack_data[i]);
	printf("END\n");
    }
    else
    {
	for(i=stack_attr[id].top; i>=stack_attr[id].start; i--)
	    printf("[%d]   ", stack_data[i]);
	printf("END\n");
    }
}


int
push(int id, int item)
{
    if((stack_attr[id].top + 1) == *(stack_attr[id].end))
    {
	printf("STACK[%d] is full. can not push [%d]\n", id, item);
	return -1;
    }

    if(id%2 == 0)
    {
	/* Even numbered stacks will always grow upwards. i.e, 
	 * their top should always be incremented to insert items.
	 */

	
	stack_data[++(stack_attr[id].top)] = item;
	printf("Pushing an item (%d) at %d\n", item, (stack_attr[id].top));
    }
    else
    {
	stack_data[--(stack_attr[id].top)] = item;
	printf("Pushing an item (%d) at %d\n", item, (stack_attr[id].top));
    }

    return 0;
}

int
pop(int id)
{
    int item = -1;

    printf("REMOVING AN ITEM (stack-%d)   top (%d)\n", id, stack_attr[id].top);
    if(id%2 == 0)
    {
	if((stack_attr[id].top) < (stack_attr[id].start))
	{
	    printf("STACK[%d] is empty\n", id);
	    return -1;
	}

	item = stack_data[(stack_attr[id].top)--];
	printf("ITEM DELETED	:   [%d]\n", item);
	return item;
    }
    else
    {
	if((stack_attr[id].top) > (stack_attr[id].start))
        {   
            printf("STACK[%d] is empty\n", id);
            return -1;
        }

        item = stack_data[(stack_attr[id].top)++];
	printf("ITEM DELETED	:   [%d]\n", item);
        return item;
    }
}


void
init_stack()
{
    static int end = 9;

    stack_attr[0].start = 0;
    stack_attr[0].top = -1;
    stack_attr[0].end =  &stack_attr[0].top;

    stack_attr[1].start = 6;
    stack_attr[1].end =  &stack_attr[0].top;
    stack_attr[1].top = stack_attr[1].start + 1;

    stack_attr[2].start = 7;
    stack_attr[2].top = stack_attr[2].start -1; 
    stack_attr[2].end = &end; 

}


int
main()
{
    init_stack();

    push(0, 10);
    push(1, 11);
    push(2, 12);
    
    push(0, 20);
    push(1, 22);
    push(2, 32);

    print_stack(0);
    print_stack(1);
    print_stack(2);

    pop(0);
    pop(1);
    pop(2);

    print_stack(0);
    print_stack(1);
    print_stack(2);

    pop(0);
    pop(1);
    pop(2);

    print_stack(0);
    print_stack(1);
    print_stack(2);

    pop(0);
    pop(1);
    pop(2);

    return 0;
}

