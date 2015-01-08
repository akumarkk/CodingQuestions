#include <stdio.h>

int
main()
{
    int a = 100, b = 200;
    int const *p1;
    const int *p2;

    p1 = &a;
    p2 = &b;

    printf("p1 = %d	p2 = %d\n", *p1, *p2);

    //*p1 = b;//should be an error
    p1 = &b;

    printf("p1 = %d	p2 = %d\n", *p1, *p2);
    
    return 0;
}
