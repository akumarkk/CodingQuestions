#include <stdio.h>
#include <stdlib.h>

typedef struct small_
{
    int sdata;
    int item;
}small_t;


typedef struct big_
{
    int data;
    struct small_ *small;
    int data2;
}big_t;


int
main()
{
    small_t small;
    big_t big, big1;

    small.sdata = 100;
    small.item = 120;

    big.data = 200;
    big.data2 = 300;
    big.small = &small;

    printf("data    =	%d\ndata2   =	%d\n", big.data, big.data2);
    printf("sdata   =	%d\nitem    =	%d\n", big.small->sdata, big.small->item);
    
    big1 = big;
    printf("---------- BIG1------------\n");
    printf("data    =	%d\ndata2   =	%d\n", big1.data, big1.data2);
    printf("sdata   =	%d\nitem    =	%d\n", big1.small->sdata, big1.small->item);
    

    return 0;
}
