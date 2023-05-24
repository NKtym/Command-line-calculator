#include <string.h>

#define ZEROASCII 48
#define NINEASCII 57

int correctness_of_input_data(char* str){
	for (char *a = str; *a != '\0'; a++){	
		if((*a>=ZEROASCII && *a<=NINEASCII) || *a=='+' || *a=='-' || *a=='*' || *a=='/')
			continue;	
		else
			return 1;
	}
	return 0;
}
