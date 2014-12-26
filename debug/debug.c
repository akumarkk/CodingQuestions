#include <stdio.h>
#define DEBUG 

// This method requires atleast two arguments. fmt and other.
// This can be eliminated by just usimg __VA_ARGS__
//#define debug(fmt, ...) do{
    //fprintf(stderr, "%s(%d): "fmt  "\n", __FUNCTION__, __LINE__, __VA_ARGS__);
#define debug(...) do{\
    if(DEBUG)\
    fprintf(stderr,  ##__VA_ARGS__);\
}while(0)

int
main()
{
    int i=10;

    if(10){
	debug("Hi, welcome to %s\n", "Utah");
    }
    else
    {
	debug("Welcome to else %s\n", "UTAH");
    };

    debug("Value of i = %d\n", i);

    return 0;
}
