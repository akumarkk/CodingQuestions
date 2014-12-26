#include <stdio.h>
#include <arpa/inet.h>



#define DEBUG 1

#define debug(fmt, ...) \
    do{\
	if(DEBUG)\
	    fprintf(stdout, "%s(%d):" fmt "\n", __FUNCTION__, __LINE__, __VA_ARGS__);\
    }while(0)

union test_
{
    char ch[2];
    short var;
};

void
test_using_union()
{
    union test_ t;
    t.var = 0x4567;

    debug("[0] = %04x	[1] = %04x\n", t.ch[0], t.ch[1]);
    if(t.ch[0] == 0x67)
	debug("Little endinan machine", "");
    else
	debug("Big endian machine", "");
}
	
int
main()
{
    unsigned short int n = 0x90783456;
    unsigned long int n1 = 0x9078345689;

    printf("short = %u	long=%u\n", sizeof(short), sizeof(long));
    printf("n = %x  n1 = %x\n", n, n1);

    if(htons(n) != n)
	printf("Little endian %x\n", htons(n));
    else
	printf("Big endian %x\n", htons(n));

    if(htonl(n1) != n1)
	printf("Little endian %x\n", htonl(n1));
    else
	printf("Big endian %x\n", htonl(n1));

    test_using_union();
    return 0;
}
