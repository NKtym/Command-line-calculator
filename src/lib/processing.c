#include <stdio.h>
#include <stdlib.h>

#include <lib/stack.h>

#define ZEROASCII 48
#define NINEASCII 57

void free_cmdcalc(struct stack_double* doub, struct stack_char* ch, char *s){
	free(s);
	free(ch);
	free(doub);
}

int check_simvol(char* tmp){
	if(*tmp>=ZEROASCII && *tmp<=NINEASCII)
		return 1;
	if(*tmp=='+' || *tmp=='-')
		return 2;
	if(*tmp=='*' || *tmp=='/')
		return 3;
	return 0;
} 

int stack_filling(struct stack_char* ch, struct stack_double* doub,char* tmp){
	static int flag;
	if(check_simvol(tmp)==1 && flag == 0){
		double i=atof(tmp);
		stack_double_push(doub,i);
		return 0;
	}
	if(check_simvol(tmp)==1 && flag == 1){
		double i=atof(tmp);
		stack_double_push(doub,i);
		flag = 0;
		return 1;
	}
	if(check_simvol(tmp)==2){
		stack_char_push(ch, *tmp);
		return 0;
	}
	if(check_simvol(tmp)==3){
		flag=1;
		stack_char_push(ch, *tmp);
		return 0;
	}
	return 0;
}

double math(double x, double y, char s){
	if(s=='*')
		return x * y;
	else if(s=='/')
		return x / y;
	else if(s=='-')
		return x - y;
	else if(s=='+')
		return x + y;
	return 0;
}

double process(struct stack_char* ch, struct stack_double* doub, double result){
	while(ch->size != 0 && doub->size != 0){
		result=math(stack_double_pop(doub),stack_double_pop(doub),stack_char_pop(ch));
		stack_double_push(doub,result);
	}
	return result;
}
