#include <stdio.h>

typedef struct test_
{
    int	    test1;
    char    test2[10];
    float   test3;
    char    test4;
}test_t;

int
get_size()
{
    unsigned int addr = 0;

    printf("addr start = %lu\n", (test_t *)(0));
    printf("addr next  = %lu\n", ((test_t *)0+(1)));
    printf("addr next  = %lu\n", ((test_t *)NULL+(1)));
    
    addr = (int)((test_t *)NULL+(1)) -(int)( (test_t *)(0));
    printf("addr = %lu\n", addr);


    printf("size       = %lu\n",
	   (unsigned int) ((test_t *)NULL+1) - (unsigned int)((test_t *) NULL));

    //return ((int)((test_t *) NULL - ((test_t *)NULL+1)));
    
    return addr;
}

int
get_offset()
{
    int offset = 0;
    // We will get SEGFAULT only for ((test_t *)0)->test3
    // as it tries to dereference the memory.

    offset = &((test_t *)0)->test3;
    return offset;
}


int
main()
{
    test_t t;
    unsigned ret = 0;
    printf("size of struct = %u\n", sizeof(test_t));
    printf("size of float  = %u\n", sizeof(float));
    ret = get_size();

    ret = get_offset();
    printf("offset = %u\n", ret);
    printf("offset by struct = %u\n", (int)(&(t.test3)) - (int)(&(t)));

    printf("size of test_t = %u\n", ret);
    return 0;
}
