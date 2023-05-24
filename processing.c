#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#define ZEROASCII 48
#define NINEASCII 57

int check_simvol(char* tmp){
	if(*tmp>=ZEROASCII && *tmp<=NINEASCII){
		return 1;
	}
	if(*tmp=='+' || *tmp=='-' || *tmp=='*' || *tmp=='/'){
		return 2;
	}
	return 0;
} 

void stack_filling(struct stack_char* ch, struct stack_double* doub,char* tmp){
	if(check_simvol(tmp)==1){
		double i=atof(tmp);
		stack_double_push(doub,i);
	}
	else if(check_simvol(tmp)==2){
		stack_char_push(ch, *tmp);
	}
}

double math(double x, double y, char s){
	if(s=='*')
		return x * y
	else if(s=='/')
		return x / y
	else if(s=='-')
		return x - y
	else if(s=='+')
		return x + y
}

double process(double result){
	return result;
}
