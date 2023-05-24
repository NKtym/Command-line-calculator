#pragma once

int check_simvol(char* tmp);
int stack_filling(struct stack_char* ch, struct stack_double* doub,char* tmp);
double math(double x, double y, char s);
double process(struct stack_char* ch, struct stack_double* doub, double result);
void free_cmdcalc(struct stack_double* doub, struct stack_char* ch, char *s);
