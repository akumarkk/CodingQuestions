#include <stdio.h>
#include <stdarg.h>
#define DEBUG 1
#define debug(fmt, ...) \
            do { \
		if (DEBUG) \
		    fprintf(stdout,"%s(%d): "fmt"\n", __FUNCTION__, __LINE__, __VA_ARGS__);\
	    } while (0)


int main(void) {
        char str[100] = "Utah";
        debug("How are you %s", str);
        if(DEBUG == 0)
            printf("This time debugs are disabled\n");
        else
            printf("DEBUGs are enabled\n");

        debug("Good bye!!!", "");
        return 0;
}

