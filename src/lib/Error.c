#include <string.h>

#define ZEROASCII 48
#define NINEASCII 57

int correctness_of_input_data(char* str){
	for (char *a = str; *a != '\0'; a++){	
		if((*a>=ZEROASCII && *a<=NINEASCII) || *a=='+' || *a=='-' || *a=='*' || *a=='/' || *a=='(' || *a==')' || *a==' ')
			continue;	
		else
			return 1;
	}
	return 0;
}

int check_for_expression_signs(char* str){
	static int flag = 0;
	for (char *a = str; *a != '\0'; a++){
		if(*a=='+' || *a=='-' || *a=='*' || *a=='/'){
			flag++;
		}
		else
			flag=0;
		if(flag>0 && ((*(a-1)>=ZEROASCII && *(a-1)<=NINEASCII) || (*(a+1)>=ZEROASCII && *(a+1)<=NINEASCII)))
			return 1; 
		else if(flag>1)
			return 1;
	}
	return 0;
}

int check_for_expression_signs2(char* str){
	static int cnt = 0;
	if(*str >= ZEROASCII && *str <=NINEASCII)
		cnt++;
	else
		cnt = 0;
	if(cnt>1)
		return 1;
	return 0;
}

int сheck_for_a_valid_entry(char* str){
	for (char *a = str; *a != '\0'; a++){
		if(*a==' ')
			return 1;
	}
	return 0;		
}
