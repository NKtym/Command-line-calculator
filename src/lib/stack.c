#include <stdio.h>
#include <stdlib.h>

#include <lib/stack.h>
#include <lib/listnode.h>

struct stack_double *stack_double_create()
{
	struct stack_double *s = malloc(sizeof(*s));
	if (s != NULL) {
		s->size = 0;
		s->top = NULL;
	}
	return s;
}

struct stack_char *stack_char_create()
{
	struct stack_char *s = malloc(sizeof(*s));
	if (s != NULL) {
		s->size = 0;
		s->top = NULL;
	}
	return s;
}

void stack_double_free(struct stack_double *s)
{
	while (s->size > 0)
		stack_double_pop(s);
	free(s);
}

void stack_char_free(struct stack_char *s)
{
	while (s->size > 0)
		stack_char_pop(s);
	free(s);
}

int stack_double_push(struct stack_double *s, double value)
{
	s->top = list_double_addfront(s->top, value);
	if (s->top == NULL) {
		printf("Stack overflow\n");
		return -1;
	}
	s->size++;
	return 0;
}

int stack_char_push(struct stack_char *s, char value)
{
	s->top = list_char_addfront(s->top, value);
	if (s->top == NULL) {
		printf("Stack overflow\n");
		return -1;
	}
	s->size++;
	return 0;
}

double stack_double_pop(struct stack_double *s)
{
	struct listnode_double *next;
	double value;
	if (s->top == NULL) {
		printf("Stack underflow\n");
		return -1;
	}
	next = s->top->next;
	value = s->top->value;
	free(s->top);
	s->top = next;
	s->size--;
	return value;
}

char stack_char_pop(struct stack_char *s)
{
	struct listnode_char *next;
	char value;
	if (s->top == NULL) {
		printf("Stack underflow\n");
		return -1;
	}
	next = s->top->next;
	value = s->top->value;
	free(s->top);
	s->top = next;
	s->size--;
	return value;
}
