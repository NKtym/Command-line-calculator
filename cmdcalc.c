#include <stdio.h>

#include "Error.h"

int main(){
	char* str;
	scanf("%s", str);
	printf("%s\n",str);
	if(Correctness_of_input_data(str)){
		printf("Некоректные входные данные\n");
		return -1;
	}
	return 0;
}
