#pragma once

struct stack_double{
    struct listnode_double *top;
    int size;
};

struct stack_char{
    struct listnode_char *top;
    int size;
};

struct stack_double *stack_double_create();
struct stack_char *stack_char_create();
int stack_double_push(struct stack_double *s, double value);
int stack_char_push(struct stack_char *s, char value);
double stack_double_pop(struct stack_double *s);
char stack_char_pop(struct stack_char *s);
