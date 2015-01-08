#include <stdio.h>

int
main()
{
    int a = 100, b = 200;
    int *const ptr = &a; // Should be initialized whenever it is declared
    //ptr = &a; error

    printf("Value of ptr = %d\n", *ptr);
    //ptr = &b; // Should be an error

    *ptr = b; // Not an error
    printf("Value of ptr = %d\n", *ptr);
    
    return 0;
}
