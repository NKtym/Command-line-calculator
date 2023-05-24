#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Error.h"
#include "stack.h"
#include "processing.h"

#define MAXOP 100

int main(int argc, char* argv[]){
	argv++;
	struct stack_double* doub=stack_double_create();
	struct stack_char* ch=stack_char_create();
	char *s = malloc(MAXOP);
	char* delim = malloc(1);
	char *tmp = malloc(MAXOP);
	//double result;
	delim=" ";
	strcpy(s,*argv);
	printf("%s\n",s);
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
		stack_filling(ch,doub,tmp);
		tmp = strtok(NULL,delim);
	}
	printf("%c\n",stack_char_pop(ch));
	printf("%lf\n",stack_double_pop(doub));
	printf("%lf\n",stack_double_pop(doub));
	free_cmdcalc(doub,ch,s);
	return 0;
}
