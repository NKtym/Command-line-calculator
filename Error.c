#include <string.h>

#define ZEROASCII 48
#define NINEASCII 57

int Correctness_of_input_data(char* str){
	for(int i=0,i<strlen(str),i++){
		if((str[i]>=ZEROASCII && str[i]<=NINEASCII) || str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='\'){
			continue;	
		}
		else{
			return 1;
		}
	}
	return 0; 
}
