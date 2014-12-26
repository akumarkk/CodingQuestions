#include <stdio.h>
#define DEBUG 1
#define debug_print(fmt, ...) \
            do { if (DEBUG) fprintf(stderr,"%s(%d): "fmt, __FUNCTION__, __LINE__, __VA_ARGS__); } while (0)
            
            
int main(void) {
	char str[100] = "Utah";
	debug_print("How are you %s", str);
        if(DEBUG == 0)
            printf("This time debugs are disabled\n");
        else
            printf("DEBUGs are enabled\n");

        debug_print("Good bye!!!\n", "");
	return 0;
}

