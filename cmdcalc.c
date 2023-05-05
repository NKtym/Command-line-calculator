#include <stdio.h>

#include "Error.h"

int main(){
	char* str;
	scanf("%255[^\n\r]", str);
	if(Correctness_of_input_data(str)){
		printf("Некоректные входные данные\n");
		return -1;
	}
	printf("%s\n",str);
	return 0;
}
