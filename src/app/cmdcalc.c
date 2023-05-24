#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <lib/Error.h>
#include <lib/stack.h>
#include <lib/processing.h>

#define MAXOP 100

int main(int argc, char* argv[]){
	argv++;
	struct stack_double* doub=stack_double_create();
	struct stack_char* ch=stack_char_create();
	char *s = malloc(MAXOP);
	char* delim = malloc(1);
	char *tmp = malloc(MAXOP);
	double result;
	delim=" ";
	strcpy(s,*argv);
	printf("%s = ",s);
	tmp=strtok(s,delim);
	while(tmp != NULL){
		if(correctness_of_input_data(tmp)){
			printf("Не корректные входные данные\n");
			free_cmdcalc(doub,ch,s);
			return -1;
		}
		if(check_for_expression_signs(tmp) || check_for_expression_signs2(tmp)){
			printf("Не корректная постановка знаков действий\n");
			free_cmdcalc(doub,ch,s);
			return -1;
		}
		if(сheck_for_a_valid_entry(tmp)){
			printf("Не корректная постановка пробелов в выражении\n");
			free_cmdcalc(doub,ch,s);
			return -1;
		}
/*!*/		if(stack_filling(ch,doub,tmp)){
			result=math(stack_double_pop(doub),stack_double_pop(doub),stack_char_pop(ch));
			stack_double_push(doub,result);
		}
		tmp = strtok(NULL,delim);
	}
	result=process(ch, doub, result);
	printf("%lf\n", result);
	free_cmdcalc(doub,ch,s);
	return 0;
}
